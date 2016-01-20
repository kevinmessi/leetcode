#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> paths(n, 0);
    paths[0] = 1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (obstacleGrid[i][j] == 1)
                paths[j] = 0;
            else if (j > 0)
                paths[j] += paths[j - 1];
        }
    }
    return paths[n - 1];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

