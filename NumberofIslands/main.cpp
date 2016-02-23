#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int numIslands1(vector<vector<char>> &grid)
{
    if (grid.empty()) return 0;
    int islands = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '0') continue;
            ++islands;
            queue<pair<int, int>> island;
            island.push(make_pair(i, j));
            grid[i][j] = '0';
            while (!island.empty())
            {
                auto pos = island.front();
                island.pop();
                if (pos.first > 0 && grid[pos.first - 1][pos.second] == '1')
                {
                    island.push(make_pair(pos.first - 1, pos.second));
                    grid[pos.first - 1][pos.second] = '0';
                }
                if (pos.first < m - 1 && grid[pos.first + 1][pos.second] == '1')
                {
                    island.push(make_pair(pos.first + 1, pos.second));
                    grid[pos.first + 1][pos.second] = '0';
                }
                if (pos.second > 0 && grid[pos.first][pos.second - 1] == '1')
                {
                    island.push(make_pair(pos.first, pos.second - 1));
                    grid[pos.first][pos.second - 1] = '0';
                }
                if (pos.second < n - 1 && grid[pos.first][pos.second + 1] == '1')
                {
                    island.push(make_pair(pos.first, pos.second + 1));
                    grid[pos.first][pos.second + 1] = '0';
                }
            }
        }
    }
    return islands;
}

void dfs(vector<vector<char>> &grid, int x, int y)
{
    int m = grid.size(), n = grid[0].size();
    grid[x][y] = '0';
    if (x > 0     && grid[x - 1][y] == '1') dfs(grid, x - 1, y);
    if (x < m - 1 && grid[x + 1][y] == '1') dfs(grid, x + 1, y);
    if (y > 0     && grid[x][y - 1] == '1') dfs(grid, x, y - 1);
    if (y < n - 1 && grid[x][y + 1] == '1') dfs(grid, x, y + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty()) return 0;
    int islands = 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == '0') continue;
            ++islands;
            dfs(grid, i, j);
        }
    }
    return islands;
}

vector<vector<char>> transform(vector<string> &v)
{
    int len = v.size();
    vector<vector<char>> grid(len);
    for (int i = 0; i < len; ++i)
    {
        for (char c : v[i])
            grid[i].push_back(c);
    }
    return grid;
}

int main()
{
    vector<string> v {"11111011111111101011",
                      "01111111111110111110",
                      "10111001101111111111",
                      "11110111111111111111",
                      "10011111111111111111",
                      "10111111011101110111",
                      "01111111111101101111",
                      "11111111111101111011",
                      "11111111110111111111",
                      "11111111111111111111",
                      "01111111011111111111",
                      "11111111111111111111",
                      "11111111111111111111",
                      "11111011111110111111",
                      "10111110111011110111",
                      "11111111111101111110",
                      "11111111111110111100",
                      "11111111111111111111",
                      "11111111111111111111",
                      "11111111111111111111"};
    vector<vector<char>> grid = transform(v);
    cout << numIslands(grid) << endl;
    return 0;
}

