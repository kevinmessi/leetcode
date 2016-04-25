#include <iostream>
#include <vector>

using namespace std;

bool isMatch1(string s, string p)
{
    int n = s.length(), m = p.length();
    for (int i = 0; i < m; ++i)
    {
        if (i + 1 < m && p[i + 1] == '*')
        {
            if (isMatch1(s.substr(i), p.substr(i + 2))) return true;
            for (int j = i; j < n && (p[i] == '.' || s[j] == p[i]); ++j)
            {
                if (isMatch1(s.substr(j + 1), p.substr(i + 2))) return true;
            }
            return false;
        }
        else
        {
            if (i >= n || (p[i] != '.' && s[i] != p[i])) return false;
        }
    }
    return m == n;
}

bool isMatch2(string s, string p)
{
    int m = p.length();
    if (m == 0) return s.empty();
    if (m > 1 && p[1] == '*')
        return isMatch2(s, p.substr(2)) || (!s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch2(s.substr(1), p));
    else
        return !s.empty() && (p[0] == '.' || s[0] == p[0]) && isMatch2(s.substr(1), p.substr(1));
}

bool isMatch3(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> match(n + 1, vector<int>(m + 1, 0));
    match[0][0] = 1;
    for (int j = 2; j <= m; ++j)
        match[0][j] = p[j - 1] == '*' && match[0][j - 2];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (p[j - 1] != '*')
                match[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && match[i - 1][j - 1];
            else
                match[i][j] = match[i][j - 2] || (p[j - 2] == '.' || s[i - 1] == p[j - 2]) && match[i - 1][j];
        }
    }
    return match[n][m];
}

bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<int> match(m + 1, 0);
    match[0] = 1;
    for (int j = 2; j <= m; ++j)
        match[j] = p[j - 1] == '*' && match[j - 2];
    for (int i = 1; i <= n; ++i)
    {
        int pre = match[0];
        match[0] = 0;
        for (int j = 1; j <= m; ++j)
        {
            int temp = match[j];
            if (p[j - 1] != '*')
                match[j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && pre;
            else
                match[j] = match[j - 2] || (p[j - 2] == '.' || s[i - 1] == p[j - 2]) && match[j];
            pre = temp;
        }
    }
    return match[m];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

