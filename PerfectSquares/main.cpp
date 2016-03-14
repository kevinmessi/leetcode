#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

int numSquares1(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j * j <= i; ++j)
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
    }
    return dp.back();
}

int numSquares2(int n)
{
    int num = 0;
    queue<int> q;
    q.push(n);
    vector<int> visited(n + 1, 0);
    visited[n] = 1;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            n = q.front();
            if (n == 0) return num;
            for (int i = sqrt(n); i > 0; --i)
            {
                int p = n - i * i;
                if (!visited[p])
                {
                    q.push(p);
                    visited[p] = 1;
                }
            }
            q.pop();
        }
        ++num;
    }
    return num;
}

bool is_square(int n)
{
    int root = sqrt(n);
    return root * root == n;
}

int numSquares(int n)
{
    if (is_square(n)) return 1;
    while ((n & 3) == 0)
        n >>= 2;
    if ((n & 7) == 7) return 4;
    for (int i = sqrt(n); i > 0; --i)
    {
        if (is_square(n - i * i)) return 2;
    }
    return 3;
}

int main()
{
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;
    cout << numSquares(50) << endl;
    cout << numSquares(7168) << endl;
    return 0;
}

