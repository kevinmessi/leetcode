#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    vector<int> squares(n + 1, 0);
    int length = 0, pre = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int temp = squares[j + 1];
            if (matrix[i][j] == '1')
            {
                squares[j + 1] = min(pre, min(squares[j], squares[j + 1])) + 1;
                length = max(length, squares[j + 1]);
            }
            else squares[j + 1] = 0;
            pre = temp;
        }
    }
    return length * length;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

