#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

bool isPalindrome(const string &word, int i, int j)
{
    while (i < j)
    {
        if (word[i++] != word[j--])
            return false;
    }
    return true;
}

vector<vector<int>> palindromePairs1(vector<string> &words)
{
    vector<vector<int>> pairs;
    unordered_map<string, int> index;
    int n = words.size();
    for (int i = 0; i < n; ++i)
        index[words[i]] = i;
    for (int i = 0; i < n; ++i)
    {
        int len = words[i].length();
        for (int j = 0; j <= len; ++j)
        {
            if (isPalindrome(words[i], 0, j - 1))
            {
                string r2(words[i].rbegin(), words[i].rbegin() + len - j);
                if (index.find(r2) != index.end() && index[r2] != i)
                    pairs.push_back({ index[r2], i });
            }
            if (j < len && isPalindrome(words[i], j, len - 1))
            {
                string r1(words[i].rend() - j, words[i].rend());
                if (index.find(r1) != index.end() && index[r1] != i)
                    pairs.push_back({ i, index[r1] });
            }
        }
    }
    return pairs;
}

vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> pairs;
    unordered_map<string, int> index;
    set<int> nums;
    int n = words.size();
    for (int i = 0; i < n; ++i)
    {
        index[words[i]] = i;
        nums.insert(words[i].length());
    }
    for (int i = 0; i < n; ++i)
    {
        string rs(words[i]);
        reverse(rs.begin(), rs.end());
        if (index.find(rs) != index.end() && index[rs] != i)
            pairs.push_back({ i, index[rs] });
        int len = rs.length();
        auto pos = nums.find(len);
        for (auto it = nums.begin(); it != pos; ++it)
        {
            int j = *it;
            if (isPalindrome(rs, j, len - 1))
            {
                string r2 = rs.substr(0, j);
                if (index.count(r2)) pairs.push_back({ index[r2], i });
            }
            if (isPalindrome(rs, 0, len - j - 1))
            {
                string r1 = rs.substr(len - j);
                if (index.count(r1)) pairs.push_back({ i, index[r1] });
            }
        }
    }
    return pairs;
}

#ifdef Memory_Limit_Exceeded

struct TrieNode
{
    TrieNode *next[26];
    int index;
    vector<int> list;
    TrieNode()
    {
        memset(next, 0, sizeof next);
        index = -1;
    }
};

void add(TrieNode *root, const string &word, int idx)
{
    for (int i = word.length() - 1; i >= 0; --i)
    {
        if (!root->next[word[i] - 'a']) root->next[word[i] - 'a'] = new TrieNode();
        if (isPalindrome(word, 0, i)) root->list.push_back(idx);
        root = root->next[word[i] - 'a'];
    }
    root->index = idx;
    root->list.push_back(idx);
}

void freeTrie(TrieNode *root)
{
    if (!root) return;
    for (auto node : root->next)
        free(node);
    delete root;
}

vector<vector<int>> palindromePairs(vector<string> &words)
{
    vector<vector<int>> pairs;
    TrieNode *root = new TrieNode();
    int n = words.size();
    for (int i = 0; i < n; ++i)
        add(root, words[i], i);
    for (int i = 0; i < n; ++i)
    {
        TrieNode *node = root;
        int len = words[i].size();
        for (int j = 0; j < len && node; ++j)
        {
            if (node->index >= 0 && node->index != i && isPalindrome(words[i], j, len - 1))
                pairs.push_back({ i, node->index });
            node = node->next[words[i][j] - 'a'];
        }
        if (!node) continue;
        for (int j : node->list)
        {
            if (i != j)
                pairs.push_back({ i, j });
        }
    }
    freeTrie(root);
    return pairs;
}

#endif

int main()
{
    //    Example 1:
    //    Given words = ["bat", "tab", "cat"]
    //    Return [[0, 1], [1, 0]]
    //    The palindromes are ["battab", "tabbat"]
    //    Example 2:
    //    Given words = ["abcd", "dcba", "lls", "s", "sssll"]
    //    Return [[0, 1], [1, 0], [3, 2], [2, 4]]
    //    The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
    vector<string> words{ "bat", "tab", "cat", "ab", "at" };
    PrintMatrix(palindromePairs(words));
    cout << endl;
    words = { "abcd", "dcba", "lls", "s", "sssll" };
    PrintMatrix(palindromePairs(words));
    return 0;
}
