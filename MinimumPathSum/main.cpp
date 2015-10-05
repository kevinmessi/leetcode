#include <iostream>
#include <vector>

using namespace std;

void PrintMatrix(vector<vector<int> > &matrix)
{
    int m = matrix.size();
    for(int i = 0;i < m;++i)
    {
        int n = matrix[i].size();
        for(int j = 0;j < n;++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int minPathSum2(vector<vector<int> > &grid)
{
    int m = grid.size();
    if(m <= 0) return 0;
    int n = grid[0].size();
    int sum[m][n];
    sum[0][0] = grid[0][0];
    for(int i = 1;i < m;++i)
    {
        sum[i][0] = sum[i-1][0] + grid[i][0];
    }
    for(int j = 1;j < n;++j)
    {
        sum[0][j] = sum[0][j-1] + grid[0][j];
    }
    int mn = min(m,n);
    for(int k = 1;k < mn;++k)
    {
        for(int i = k;i < m;++i)
        {
            sum[i][k] = min(sum[i-1][k],sum[i][k-1]) + grid[i][k];
        }
        for(int j = k+1;j < n;++j)
        {
            sum[k][j] = min(sum[k][j-1],sum[k-1][j]) + grid[k][j];
        }
    }
    return sum[m-1][n-1];
}

int minPathSum(vector<vector<int> > &grid)
{
    int m = grid.size();
    if(m == 0) return 0;
    int n = grid[0].size();
    int sum[n];
    sum[0] = grid[0][0];
    for(int k = 1;k < n;++k)
    {
        sum[k] = sum[k-1] + grid[0][k];
    }
    for(int i = 1;i < m;++i)
    {
        sum[0] += grid[i][0];
        for(int j = 1;j < n;++j)
        {
            sum[j] = min(sum[j], sum[j-1]) + grid[i][j];
        }
    }
    return sum[n-1];
}

int main()
{
    vector<vector<int> > matrix;
    matrix.push_back({1,2,1,7});
    matrix.push_back({0,1,5,0});
    matrix.push_back({4,3,2,1});
    matrix.push_back({0,0,3,1});
    PrintMatrix(matrix);
    cout << "--------" <<endl;
    cout << minPathSum(matrix) <<endl;
    return 0;
}

