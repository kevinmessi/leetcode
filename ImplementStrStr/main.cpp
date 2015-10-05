#include <iostream>
#include <vector>

using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.length();
    int m = needle.length();
    if (m == 0) return 0;
    vector<int> next(m, 0);
    for (int i = 1, q = 0;i < m;++i)
    {
        while (q > 0 && needle[q] != needle[i]) q = next[q - 1];
        if (needle[q] == needle[i]) ++q;
        next[i] = q;
    }
    for (int i = 0, q = 0;i < n;++i)
    {
        while (q > 0 && needle[q] != haystack[i]) q = next[q - 1];
        if (needle[q] == haystack[i]) ++q;
        if (q == m) return i - m + 1;
    }
    return -1;
}

int main()
{
    cout << strStr("cbababq", "ab") << endl;
    return 0;
}

