#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict)
{
    int len = s.length();
    if (len == 0) return false;
    vector<unsigned char> breaks(len + 1, 0);
    breaks[0] = 1;
    for (int i = 1; i <= len; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (breaks[i - j] && wordDict.find(s.substr(len - i, j)) != wordDict.end())
            {
                breaks[i] = 1;
                break;
            }
        }
    }
    return breaks[len];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

