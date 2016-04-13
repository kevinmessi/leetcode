#include <iostream>
#include <vector>

using namespace std;

bool isInterleave1(string s1, string s2, string s3)
{
    int p = s1.length(), q = s2.length(), n = s3.length();
    if (p + q != n) return false;
    vector<vector<int>> dp(p + 1, vector<int>(q + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= p; ++i)
    {
        for (int j = 0; j <= q; ++j)
        {
            if (i > 0 && s1[i - 1] == s3[i + j - 1]) dp[i][j] += dp[i - 1][j];
            if (j > 0 && s2[j - 1] == s3[i + j - 1]) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[p][q] > 0;
}

bool isInterleave(string s1, string s2, string s3)
{
    int p = s1.length(), q = s2.length(), n = s3.length();
    if (p + q != n) return false;
    vector<int> dp(q + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= p; ++i)
    {
        for (int j = 0; j <= q; ++j)
        {
            if (i > 0 && s1[i - 1] != s3[i + j - 1]) dp[j] = 0;
            if (j > 0 && s2[j - 1] == s3[i + j - 1]) dp[j] += dp[j - 1];
        }
    }
    return dp[q] > 0;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
