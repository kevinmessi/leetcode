#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix)
{
    return 0;
}

int main()
{
    vector<vector<char>> matrix
    {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' }
    };
    cout << maximalRectangle(matrix) << endl;
    return 0;
}

