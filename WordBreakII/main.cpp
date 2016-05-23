#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


vector<string> wordBreak(const string &s, int n, const unordered_set<string> &wordDict,
                         vector<unsigned char> &solved, vector<vector<string>> &table)
{
    if (solved[n]) return table[n];
    for (int j = 0; j < n; ++j)
    {
        string word = s.substr(j, n - j);
        if (wordDict.find(word) != wordDict.end())
        {
            for (string &sln : wordBreak(s, j, wordDict, solved, table))
                table[n].push_back(sln + word + " ");
        }
    }
    solved[n] = 1;
    return table[n];
}

vector<string> wordBreak(string s, unordered_set<string> &wordDict)
{
    int len = s.length();
    vector<vector<string>> table(len + 1);
    vector<unsigned char> solved(len + 1);
    solved[0] = 1;
    table[0].push_back("");
    wordBreak(s, len, wordDict, solved, table);
    for (string &sln : table[len])
        sln.erase(sln.end() - 1);
    return table[len];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
