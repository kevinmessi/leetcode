#include <iostream>

using namespace std;

string minWindow(string s, string t)
{
    int n = s.length(), m = t.length(), count = 0, min_len = INT_MAX, begin;
    int remaining[256] = { 0 };
    for (char c : t)
        ++remaining[c];
    for (int i = 0, j = 0; i < n; ++i)
    {
        --remaining[s[i]];
        if (remaining[s[i]] >= 0)
            ++count;
        if (count >= m)
        {
            while (remaining[s[j]] < 0)
                ++remaining[s[j++]];
            if (i - j + 1 < min_len)
                min_len = i - (begin = j) + 1;
            --count;
            ++remaining[s[j++]];
        }
    }
    return min_len == INT_MAX ? "" : s.substr(begin, min_len);
}

int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
