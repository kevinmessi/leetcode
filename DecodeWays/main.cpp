#include <iostream>

using namespace std;

int numDecodings(string s)
{
    int len = s.length();
    int pre = 1, cur = s.empty() || s[0] == '0' ? 0 : 1;
    for (int i = 1; i < len; ++i)
    {
        int temp = cur;
        if (s[i] == '0') cur = 0;
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) cur += pre;
        if (cur == 0) return 0;
        pre = temp;
    }
    return cur;
}

int main()
{
    cout << numDecodings("1347615132") << endl;
    return 0;
}

