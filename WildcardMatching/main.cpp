#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool isMatch1(string s, string p)
{
    int n = s.length(), m = p.length(), pre;
    vector<int> is_matched(m + 1, 0);
    is_matched[0] = 1;
    for (int j = 1; j <= m; ++j)
        is_matched[j] = p[j - 1] == '*' && is_matched[j - 1];
    for (int i = 1; i <= n; ++i)
    {
        pre = is_matched[0];
        is_matched[0] = 0;
        for (int j = 1; j <= m; ++j)
        {
            int temp = is_matched[j];
            if (p[j - 1] == '*')
                is_matched[j] |= is_matched[j - 1];
            else
                is_matched[j] = pre && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
            pre = temp;
        }
    }
    return is_matched[m];
}

bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length(), i = 0, j = 0, star = -1, match = 0;
    while (i < n)
    {
        if (j < m && p[j] == '*')
        {
            star = j;
            match = i;
            ++j;
        }
        else if (j < m && (p[j] == '?' || s[i] == p[j]))
        {
            ++i;
            ++j;
        }
        else if (star >= 0)
        {
            j = star + 1;
            ++match;
            i = match;
        }
        else return false;
    }
    while (j < m && p[j] == '*')
        ++j;
    return j == m;
}

int main()
{
    cout << isMatch("babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", "***bba**a*bbba**aab**b") << endl;
    cout << isMatch("ab*cdec", "ab*c") << endl;
    return 0;
}

