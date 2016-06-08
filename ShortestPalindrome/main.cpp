#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string shortestPalindrome1(string s)
{
    int len = s.length();
    string p("#");
    for (char c : s)
        p.append(1, c).append(1, '#');
    const char *t = p.c_str();
    vector<int> max_len(len + 1);
    max_len[0] = 1;
    for (int i = 1, mi = 0; i <= len; ++i)
    {
        int ri = mi + max_len[mi];
        max_len[i] = ri > i ? min(max_len[2 * mi - i], ri - i) : 1;
        while (i >= max_len[i] && t[i - max_len[i]] == t[i + max_len[i]])
            ++max_len[i];
        if (i + max_len[i] > ri) mi = i;
    }
    for (int i = len; i >= 0; --i)
    {
        if (max_len[i] == i + 1)
        {
            string r = s.substr(i);
            reverse(r.begin(), r.end());
            return r + s;
        }
    }
    return "";
}

string shortestPalindrome2(string s)
{
    string r(s);
    reverse(r.begin(), r.end());
    string p = s + '#' + r;
    vector<int> next(p.length(), 0);
    for (size_t i = 1, k = 0; i < p.length(); ++i)
    {
        while (k > 0 && p[k] != p[i])
            k = next[k - 1];
        if (p[k] == p[i]) ++k;
        next[i] = k;
    }
    return r.substr(0, r.length() - next.back()) + s;
}

string shortestPalindrome(string s)
{
    if (s.empty()) return "";
    string r(s);
    reverse(r.begin(), r.end());
    string p = s + r;
    vector<int> next(p.length(), 0);
    for (size_t i = 1, k = 0; i < p.length(); ++i)
    {
        while (k > 0 && p[k] != p[i])
            k = next[k - 1];
        if (p[k] == p[i]) ++k;
        next[i] = k;
    }
    size_t x = next.back();
    while (x > s.length())
        x = next[x - 1];
    return r.substr(0, r.length() - x) + s;
}

int main()
{
    cout << shortestPalindrome("abccbabc") << endl;
    return 0;
}
