#include <iostream>
#include <vector>

using namespace std;

int minCut1(string s)
{
    int len = s.length();
    vector<int> cuts(len + 1, INT_MAX);
    cuts[0] = -1;
    vector<vector<int>> pair(len, vector<int>(len, 0));
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (s[j] == s[i] && (i - j <= 1 || pair[j + 1][i - 1]))
            {
                pair[j][i] = 1;
                cuts[i + 1] = min(cuts[i + 1], cuts[j] + 1);
            }
        }
    }
    return cuts[len];
}

int minCut(string s)
{
    int len = s.length();
    vector<int> cuts(len + 1, INT_MAX);
    cuts[0] = -1;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; i - j >= 0 && i + j < len && s[i - j] == s[i + j]; ++j)
            cuts[i + j + 1] = min(cuts[i + j + 1], cuts[i - j] + 1);
        for (int j = 0; i - j >= 0 && i + j + 1 < len && s[i - j] == s[i + j + 1]; ++j)
            cuts[i + j + 2] = min(cuts[i + j + 2], cuts[i - j] + 1);
    }
    return cuts[len];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

