#include <iostream>
#include <vector>

using namespace std;

// p(m, n) = p(m, n-1) + p(m-1, n)

int uniquePaths2(int m, int n)
{
    if(m == 1 || n == 1) return 1;
    int l = min(m, n);
    int paths[m][n];
    for(int i = 0;i < m;++i)
    {
        paths[i][0] = 1;
    }
    for(int j = 1;j < n;++j)
    {
        paths[0][j] = 1;
    }
    for(int t = 1;t < l;++t)
    {
        for(int i = t;i < m;++i)
        {
            paths[i][t] = paths[i][t-1] + paths[i-1][t];
        }
        for(int j = t + 1;j < n;++j)
        {
            paths[t][j] = paths[t][j-1] + paths[t-1][j];
        }
    }
    return paths[m-1][n-1];
}

int uniquePaths(int m, int n)
{
    if(m == 1 || n == 1) return 1;
    int paths[n];
    for(int k = 0;k < n;++k)
    {
        paths[k] = 1;
    }
    for(int i = 1;i < m;++i)
    {
        paths[0] = 1;
        for(int j = 1;j < n;++j)
        {
            paths[j] = paths[j] + paths[j-1];
        }
    }
    return paths[n-1];
}

int main()
{
    cout << uniquePaths(80, 6) << endl;
    cout << uniquePaths2(80, 6) << endl;
    return 0;
}

