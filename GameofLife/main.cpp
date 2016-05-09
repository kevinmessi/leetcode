#include <iostream>
#include <vector>

using namespace std;

void gameOfLife1(vector<vector<int>> &board)
{
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    int directions[][8] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };
    vector<vector<int>> copy(board);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int count = 0;
            for (int k = 0; k < 8; ++k)
            {
                int ii = i + directions[k][0], jj = j + directions[k][1];
                if (ii >= 0 && ii < m && jj >= 0 && jj < n && copy[ii][jj]) ++count;
            }
            if (count == 3 || count == 2 && board[i][j]) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
}

void gameOfLife2(vector<vector<int>> &board)
{
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    if (n == 0) return;
    vector<int> prev(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int temp;
        for (int j = 0; j < n; ++j)
        {
            int count = -board[i][j];
            for (int ii = max(i - 1, 0); ii < min(i + 2, m); ++ii)
            {
                for (int jj = max(j - 1, 0); jj < min(j + 2, n); ++jj)
                    count += board[ii][jj] & 1;
            }
            if (i > 0 && j > 0) board[i - 1][j - 1] = temp;
            temp = prev[j];
            prev[j] = (count | board[i][j]) == 3 ? 1 : 0;
        }
        if (i > 0) board[i - 1][n - 1] = temp;
    }
    board[m - 1] = prev;
}

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int count = -board[i][j];
            for (int ii = max(i - 1, 0); ii < min(i + 2, m); ++ii)
            {
                for (int jj = max(j - 1, 0); jj < min(j + 2, n); ++jj)
                    count += board[ii][jj] & 1;
            }
            if ((count | board[i][j]) == 3) board[i][j] |= 2;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            board[i][j] >>= 1;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
