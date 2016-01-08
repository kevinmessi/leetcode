#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

void rotate2(vector<vector<int>>& matrix)
{
    reverse(matrix.begin(), matrix.end());
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

