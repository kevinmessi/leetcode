#include <cstring>
#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

struct TrieNode
{
    TrieNode *descendants[26];
    const char *str;
    TrieNode()
    {
        memset(descendants, 0, sizeof descendants);
        str = 0;
    }
};

TrieNode *ConstructTrie(vector<string> &words)
{
    TrieNode *root = new TrieNode();
    for (const string &word : words)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->descendants[c - 'a'])
                node->descendants[c - 'a'] = new TrieNode();
            node = node->descendants[c - 'a'];
        }
        node->str = word.c_str();
    }
    return root;
}

void findWords(vector<vector<char>> &board, int row, int col, TrieNode *node, vector<string> &result)
{
    if (node->str)
    {
        result.push_back(node->str);
        node->str = 0;
    }
    if (row < 0 || row >= (int)board.size() || col < 0 || col >= (int)board[0].size()) return;
    char c = board[row][col];
    if (!c || !node->descendants[c - 'a']) return;
    node = node->descendants[c - 'a'];
    board[row][col] = 0;
    findWords(board, row - 1, col, node, result);
    findWords(board, row + 1, col, node, result);
    findWords(board, row, col - 1, node, result);
    findWords(board, row, col + 1, node, result);
    board[row][col] = c;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    TrieNode *root = ConstructTrie(words);
    int m = board.size(), n = board[0].size();
    vector<string> result;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            findWords(board, i, j, root, result);
    }
    return result;
}

int main()
{
    vector<string> words { "oath", "pea", "eat", "rain" };
    vector<vector<char>> board
    {
        { 'o', 'a', 'a', 'n'},
        { 'e', 't', 'a', 'e'},
        { 'i', 'h', 'k', 'r'},
        { 'i', 'f', 'l', 'v'}
    };
    PrintVector(findWords(board, words));
    return 0;
}
