#include <iostream>
#include <queue>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void solve1(vector<vector<char>> &board)
{
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    vector<vector<char>> visited(m, vector<char>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 'X' || visited[i][j]) continue;
            vector<pair<int, int>> points;
            bool is_surrounded = true;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            visited[i][j] = 1;
            while (!q.empty())
            {
                auto p = q.front();
                int x = p.first, y = p.second;
                q.pop();
                points.push_back(p);
                if (x > 0 && !visited[x - 1][y] && board[x - 1][y] != 'X')
                {
                    q.emplace(x - 1, y);
                    visited[x - 1][y] = 1;
                }
                if (x < m - 1 && !visited[x + 1][y] && board[x + 1][y] != 'X')
                {
                    q.emplace(x + 1, y);
                    visited[x + 1][y] = 1;
                }
                if (y > 0 && !visited[x][y - 1] && board[x][y - 1] != 'X')
                {
                    q.emplace(x, y - 1);
                    visited[x][y - 1] = 1;
                }
                if (y < n - 1 && !visited[x][y + 1] && board[x][y + 1] != 'X')
                {
                    q.emplace(x, y + 1);
                    visited[x][y + 1] = 1;
                }
                if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                    is_surrounded = false;
            }
            if (is_surrounded)
            {
                for (const auto &p : points)
                    board[p.first][p.second] = 'X';
            }
        }
    }
}

void dfs(vector<vector<char>> &board, int i, int j)
{
    int m = board.size(), n = board[0].size();
    if (board[i][j] == 'O')
    {
        board[i][j] = '*';
        if (i > 1) dfs(board, i - 1, j);
        if (i < m - 2) dfs(board, i + 1, j);
        if (j > 1) dfs(board, i, j - 1);
        if (j < n - 2) dfs(board, i, j + 1);
    }
}

void solve2(vector<vector<char>> &board)
{
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i)
    {
        dfs(board, i, 0);
        if (n > 0) dfs(board, i, n - 1);
    }
    for (int j = 1; j < n - 1; ++j)
    {
        dfs(board, 0, j);
        if (m > 0) dfs(board, m - 1, j);
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '*') board[i][j] = 'O';
        }
    }
}

void bfs(vector<vector<char>> &board, int i, int j)
{
    int m = board.size(), n = board[0].size();
    if (board[i][j] == 'O')
    {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        board[i][j] = '*';
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if (x > 0 && board[x - 1][y] == 'O')
            {
                q.emplace(x - 1, y);
                board[x - 1][y] = '*';
            }
            if (x < m - 1 && board[x + 1][y] == 'O')
            {
                q.emplace(x + 1, y);
                board[x + 1][y] = '*';
            }
            if (y > 0 && board[x][y - 1] == 'O')
            {
                q.emplace(x, y - 1);
                board[x][y - 1] = '*';
            }
            if (y < n - 1 && board[x][y + 1] == 'O')
            {
                q.emplace(x, y + 1);
                board[x][y + 1] = '*';
            }
        }
    }
}

void solve(vector<vector<char>> &board)
{
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i)
    {
        bfs(board, i, 0);
        if (n > 0) bfs(board, i, n - 1);
    }
    for (int j = 1; j < n - 1; ++j)
    {
        bfs(board, 0, j);
        if (m > 0) bfs(board, m - 1, j);
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '*') board[i][j] = 'O';
        }
    }
}

int main()
{
    vector<vector<char>> board
    {
        { 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'O', 'X' },
        { 'X', 'X', 'O', 'X' },
        { 'X', 'O', 'X', 'X' }
    };
    PrintMatrix(board);
    solve(board);
    cout << endl;
    PrintMatrix(board);
    return 0;
}
