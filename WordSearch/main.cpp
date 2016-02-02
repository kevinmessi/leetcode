#include <iostream>
#include <vector>

using namespace std;

bool exist(vector<vector<char>> &board, int i, int j, string &word, int begin)
{
    if (begin == word.length()) return true;
    int m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (board[i][j] != word[begin]) return false;
    board[i][j] = 0;
    bool result = exist(board, i - 1, j, word, begin + 1)
            || exist(board, i, j - 1, word, begin + 1)
            || exist(board, i + 1, j, word, begin + 1)
            || exist(board, i, j + 1, word, begin + 1);
    board[i][j] = word[begin];
    return result;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (board.empty() || board[0].empty()) return false;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (exist(board, i, j, word, 0)) return true;
    return false;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

