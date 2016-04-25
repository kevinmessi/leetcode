#include <iostream>
#include <unordered_map>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

vector<int> findSubstring1(string s, vector<string> &words)
{
    vector<int> indices;
    unordered_map<string, int> dict;
    for (string &word : words)
        ++dict[word];
    int n = s.length(), m = words.size(), len = words[0].length(), window = m * len;
    for (int i = 0; i + window <= n; ++i)
    {
        int counter = m;
        unordered_map<string, int> table;
        for (int j = 0; j < m; ++j)
        {
            string str = s.substr(i + j * len, len);
            if (dict.find(str) == dict.end()) break;
            if (table[str]++ < dict[str]) --counter;
        }
        if (counter == 0)
            indices.push_back(i);
    }
    return indices;
}

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> indices;
    unordered_map<string, int> dict;
    for (string &word : words)
        ++dict[word];
    int n = s.length(), m = words.size(), len = words[0].length();
    for (int i = 0; i < len; ++i)
    {
        int counter = m;
        unordered_map<string, int> table;
        for (int j = i, k = i; j <= n - len; j += len)
        {
            string str = s.substr(j, len), left = s.substr(k, len);
            if (dict.find(str) != dict.end())
            {
                if (table[str] < dict[str])
                {
                    ++table[str];
                    --counter;
                }
                else
                {
                    while (left != str)
                    {
                        ++counter;
                        --table[left];
                        k += len;
                        left = s.substr(k, len);
                    }
                    k += len;
                }
                if (counter == 0)
                {
                    indices.push_back(k);
                    ++counter;
                    --table[left];
                    k += len;
                }
            }
            else
            {
                table.clear();
                k = j + len;
                counter = m;
            }
        }
    }
    return indices;
}

int main()
{
    vector<string> words{ "foo", "bar" };
    PrintVector(findSubstring("barfoothefoobarman", words));
    words = { "aba", "bab" };
    PrintVector(findSubstring("abababababab", words));
    words = { "foo", "bar", "the" };
    PrintVector(findSubstring("barfoofoobarthefoobarman", words));
    return 0;
}
