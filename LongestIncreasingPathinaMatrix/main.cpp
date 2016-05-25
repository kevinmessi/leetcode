#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int outdegree(const vector<vector<int>> &matrix, size_t i, size_t j)
{
    int out = 0;
    if (i > 0 && matrix[i][j] < matrix[i - 1][j])
        ++out;
    if (i < matrix.size() - 1 && matrix[i][j] < matrix[i + 1][j])
        ++out;
    if (j > 0 && matrix[i][j] < matrix[i][j - 1])
        ++out;
    if (j < matrix[0].size() - 1 && matrix[i][j] < matrix[i][j + 1])
        ++out;
    return out;
}

int longestIncreasingPath1(vector<vector<int>> &matrix)
{
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), max_len = 0, count = m * n;
    vector<vector<unsigned char>> is_removed(m, vector<unsigned char>(n, 0));
    while (count > 0)
    {
        vector<pair<int, int>> removed_points;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!is_removed[i][j] && outdegree(matrix, i, j) == 0)
                    removed_points.push_back(make_pair(i, j));
            }
        }
        for (auto &p : removed_points)
        {
            matrix[p.first][p.second] = INT_MIN;
            is_removed[p.first][p.second] = 1;
        }
        count -= removed_points.size();
        ++max_len;
    }
    return max_len;
}

int longestIncreasingPath(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &memo)
{
    if (memo[row][col] > 0) return memo[row][col];
    int m = matrix.size(), n = matrix[0].size(), len = 1;
    if (row > 0 && matrix[row - 1][col] > matrix[row][col])
        len = max(len, 1 + longestIncreasingPath(matrix, row - 1, col, memo));
    if (row < m - 1 && matrix[row + 1][col] > matrix[row][col])
        len = max(len, 1 + longestIncreasingPath(matrix, row + 1, col, memo));
    if (col > 0 && matrix[row][col - 1] > matrix[row][col])
        len = max(len, 1 + longestIncreasingPath(matrix, row, col - 1, memo));
    if (col < n - 1 && matrix[row][col + 1] > matrix[row][col])
        len = max(len, 1 + longestIncreasingPath(matrix, row, col + 1, memo));
    return memo[row][col] = len;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), max_len = 0;
    vector<vector<int>> memo(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            max_len = max(max_len, longestIncreasingPath(matrix, i, j, memo));
    }
    return max_len;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
