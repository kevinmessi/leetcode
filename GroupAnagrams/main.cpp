#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

string str_sort(const string &s)
{
    int len = s.length();
    string sorted_str(len, 'a');
    int count[26] = {0};
    for (int i = 0; i < len; ++i)
        ++count[s[i] - 'a'];
    for (int i = 1; i < 26; ++i)
        count[i] += count[i-1];
    for (int i = len - 1; i >= 0; --i)
    {
        sorted_str[count[s[i] - 'a'] - 1] = s[i];
        --count[s[i] - 'a'];
    }
    return sorted_str;
}

vector<vector<string>> groupAnagrams1(vector<string>& strs)
{
    unordered_map<string, vector<string>> m;
    for (auto &s : strs)
    {
        string key(s);
        sort(key.begin(), key.end());
        m[key].push_back(s);
    }
    vector<vector<string>> groups;
    for (auto &pair : m)
    {
        sort(pair.second.begin(), pair.second.end());
        groups.push_back(pair.second);
    }
    return groups;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, multiset<string>> m;
    for (const auto &s : strs)
        m[str_sort(s)].insert(s);
    vector<vector<string>> groups;
    for (const auto &pair : m)
        groups.push_back(vector<string>(pair.second.begin(), pair.second.end()));
    return groups;
}

int main()
{
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    PrintMatrix(groupAnagrams(strs));
    return 0;
}

