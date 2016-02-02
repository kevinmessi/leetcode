#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder1(vector<vector<int>>& matrix)
{
    vector<int> result;
    int m = matrix.size();
    if (m == 0) return result;
    int n = matrix[0].size();
    int s = min(m, n);
    int imax = s >> 1;
    for (int i = 0; i < imax; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
            result.push_back(matrix[i][j]);
        for (int j = i; j < m - i - 1; ++j)
            result.push_back(matrix[j][n - i - 1]);
        for (int j = n - i - 1; j > i; --j)
            result.push_back(matrix[m - i - 1][j]);
        for (int j = m - i - 1; j > i; --j)
            result.push_back(matrix[j][i]);
    }
    if (s % 2)
    {
        if (m >= n)
        {
            for (int j = imax; j < m - imax; ++j)
                result.push_back(matrix[j][imax]);
        }
        else
        {
            for (int j = imax; j < n - imax; ++j)
                result.push_back(matrix[imax][j]);
        }
    }
    return result;
}

vector<int> spiralOrder2(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) return{};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result(m * n);
    int i = 0, l = 0, r = n - 1, u = 0, d = m - 1;
    while (true)
    {
        for (int col = l; col <= r; ++col)
            result[i++] = matrix[u][col];
        if (++u > d) break;
        for (int row = u; row <= d; ++row)
            result[i++] = matrix[row][r];
        if (--r < l) break;
        for (int col = r; col >= l; --col)
            result[i++] = matrix[d][col];
        if (--d < u) break;
        for (int row = d; row >= u; --row)
            result[i++] = matrix[row][l];
        if (++l > r) break;
    }
    return result;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) return{};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result(m * n);
    vector<vector<int>> directions{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    vector<int> steps{ n, m - 1 };
    int i = 0, id = 0, ir = 0, ic = -1;
    while (steps[id % 2])
    {
        for (int j = 0; j < steps[id % 2]; ++j)
        {
            ir += directions[id][0], ic += directions[id][1];
            result[i++] = matrix[ir][ic];
        }
        --steps[id % 2];
        id = (id + 1) % 4;
    }
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

