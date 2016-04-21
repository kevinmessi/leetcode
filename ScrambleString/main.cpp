#include <iostream>
#include <vector>

using namespace std;

bool isScramble1(const string &s1, const string &s2, int b1, int b2, int len)
{
    int m[256] = { 0 };
    bool is_same = true;
    for (int i = 0; i < len; ++i)
    {
        if (s1[b1 + i] != s2[b2 + i]) is_same = false;
        ++m[s1[b1 + i]];
        --m[s2[b2 + i]];
    }
    if (is_same) return true;
    for (int i = 0; i < len; ++i)
    {
        if (m[s1[b1 + i]] != 0)
            return false;
    }
    for (int i = 1; i < len; ++i)
    {
        if (isScramble1(s1, s2, b1, b2, i) && isScramble1(s1, s2, b1 + i, b2 + i, len - i))
            return true;
        if (isScramble1(s1, s2, b1, b2 + len - i, i) && isScramble1(s1, s2, b1 + i, b2, len - i))
            return true;
    }
    return false;
}

bool isScramble1(string s1, string s2)
{
    return isScramble1(s1, s2, 0, 0, s1.length());
}

bool isScramble2(const string &s1, const string &s2, int b1, int b2, int len,
                 vector<vector<vector<int>>> &memo)
{
    if (memo[len][b1][b2] >= 0) return memo[len][b1][b2];
    int m[256] = { 0 };
    bool is_same = true;
    for (int i = 0; i < len; ++i)
    {
        if (s1[b1 + i] != s2[b2 + i]) is_same = false;
        ++m[s1[b1 + i]];
        --m[s2[b2 + i]];
    }
    if (is_same) return memo[len][b1][b2] = true;
    for (int i = 0; i < len; ++i)
    {
        if (m[s1[b1 + i]] != 0)
            return memo[len][b1][b2] = false;
    }
    for (int i = 1; i < len; ++i)
    {
        if (isScramble2(s1, s2, b1, b2, i, memo) && isScramble2(s1, s2, b1 + i, b2 + i, len - i, memo))
            return memo[len][b1][b2] = true;
        if (isScramble2(s1, s2, b1, b2 + len - i, i, memo) && isScramble2(s1, s2, b1 + i, b2, len - i, memo))
            return memo[len][b1][b2] = true;
    }
    return memo[len][b1][b2] = false;
}

bool isScramble2(string s1, string s2)
{
    int len = s1.length();
    vector<vector<vector<int>>> memo(len + 1, vector<vector<int>>(len, vector<int>(len, -1)));
    return isScramble2(s1, s2, 0, 0, len, memo);
}

bool isScramble(string s1, string s2)
{
    int len = s1.length();
    vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(len, vector<int>(len, 0)));
    for (int j = 0; j <= len - 1; ++j)
    {
        for (int k = 0; k <= len - 1; ++k)
            dp[1][j][k] = s1[j] == s2[k];
    }
    for (int i = 2; i <= len; ++i)
    {
        for (int j = 0; j <= len - i; ++j)
        {
            for (int k = 0; k <= len - i; ++k)
            {
                for (int n = 1; n < i; ++n)
                {
                    if (dp[n][j][k] && dp[i - n][j + n][k + n])
                        dp[i][j][k] = 1;
                    else if (dp[n][j][k + i - n] && dp[i - n][j + n][k])
                        dp[i][j][k] = 1;
                }
            }
        }
    }
    return dp[len][0][0];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

