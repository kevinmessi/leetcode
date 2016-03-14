#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;
    for (int i = 0; i < m; ++i)
    {
        int L = 0, R = n - 1;
        if (matrix[i][L] > target || matrix[i][R] < target) continue;
        while (L <= R)
        {
            int M = L + (R - L) / 2;
            if (matrix[i][M] == target) return true;
            else if (matrix[i][M] > target) R = M - 1;
            else L = M + 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    if (m == 0) return false;
    int i = 0, j = matrix[0].size() - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] < target) ++i;
        else --j;
    }
    return false;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

