#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int L = 0, R = m * n - 1;
    while (L <= R)
    {
        int M = (R - L) / 2 + L;
        int x = M / n, y = M % n;
        if (matrix[x][y] == target)
            return true;
        else if (matrix[x][y] < target)
            L = M + 1;
        else
            R = M - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix;
    vector<int> v1 = {1, 3, 5, 7};
    vector<int> v2 = {10, 11, 16, 20};
    vector<int> v3 = {23, 30, 34, 50};
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    PrintMatrix(matrix);
    cout << endl;
    cout << searchMatrix(matrix, 0) << endl;
    return 0;
}

