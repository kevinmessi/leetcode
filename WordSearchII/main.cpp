#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> results;
    return results;
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
