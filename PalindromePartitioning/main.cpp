#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> partition1(string s)
{
    int len = s.length();
    vector<vector<vector<string>>> results(len + 1);
    results[0].push_back(vector<string>());
    vector<vector<int>> pair(len, vector<int>(len, 0));
    for (int i = 0; i < len; ++i)
    {
        for (int left = 0; left <= i; ++left)
        {
            if (s[left] == s[i] && (i - left <= 1 || pair[left + 1][i - 1]))
            {
                pair[left][i] = 1;
                for (auto &r : results[left])
                {
                    vector<string> ri(r);
                    ri.push_back(s.substr(left, i - left + 1));
                    results[i + 1].push_back(ri);
                }
            }
        }
    }
    return results[len];
}

void partition(string s, vector<string> &parts, vector<vector<string>> &results)
{
    int len = s.length();
    if (len == 0)
    {
        results.push_back(parts);
        return;
    }
    for (int i = 0; i < len; ++i)
    {
        int j = 0;
        for (; j < i - j && s[j] == s[i - j]; ++j)
            ;
        if (j < i - j) continue;
        parts.push_back(s.substr(0, i + 1));
        partition(s.substr(i + 1, len - i - 1), parts, results);
        parts.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> results;
    vector<string> parts;
    partition(s, parts, results);
    return results;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

