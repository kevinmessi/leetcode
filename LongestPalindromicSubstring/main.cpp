#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string preprocess(const string &s)
{
    int len = s.length();
    stringstream ss;
    ss << "#";
    for (int i = 0; i < len; ++i)
        ss << s[i] << "#";
    return ss.str();
}

string longestPalindrome(string s)
{
    string ps = preprocess(s);
    int len = ps.length(), C = 0, R = 0, mc = 0;;
    vector<int> p(len);
    for (int i = 0; i < len; ++i)
    {
        p[i] = R > i ? min(p[2 * C - i], R - i + 1) : 1;
        while (i >= p[i] && i + p[i] < len && ps[i - p[i]] == ps[i + p[i]])
            ++p[i];
        if (i + p[i] - 1 > R)
        {
            C = i;
            R = i + p[i] - 1;
        }
        if (p[i] > p[mc])
            mc = i;
    }
    return s.substr((mc - p[mc] + 1) / 2, p[mc] - 1);
}

int main()
{
    cout << longestPalindrome("sdadwaedsadas") << endl;
    return 0;
}

