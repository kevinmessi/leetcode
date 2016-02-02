#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix1(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<int>> directions{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    vector<int> steps{ n, n - 1 };
    int i = 1, id = 0, ir = 0, ic = -1;
    while (steps[id % 2])
    {
        for (int j = 0; j < steps[id % 2]; ++j)
        {
            ir += directions[id][0], ic += directions[id][1];
            matrix[ir][ic] = i++;
        }
        --steps[id % 2];
        id = (id + 1) % 4;
    }
    return matrix;
}

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));
    int i = 1, m = n * n, l = 0, r = n - 1, u = 0, d = n - 1;
    while (i <= m)
    {
        for (int col = l; col <= r; ++col)
            matrix[u][col] = i++;
        ++u;
        for (int row = u; row <= d; ++row)
            matrix[row][r] = i++;
        --r;
        for (int col = r; col >= l; --col)
            matrix[d][col] = i++;
        --d;
        for (int row = d; row >= u; --row)
            matrix[row][l] = i++;
        ++l;
    }
    return matrix;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

