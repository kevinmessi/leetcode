#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

bool wordPattern(string pattern, string str)
{
    vector<string> m(26, "");
    unordered_map<string, char> w;
    istringstream iss(str);
    int len = pattern.length(), i = 0;
    for (string word; iss >> word; ++i)
    {
        if (i >= len) return false;
        if (m[pattern[i] - 'a'].empty() && w[word] == 0)
        {
            m[pattern[i] - 'a'] = word;
            w[word] = pattern[i];
        }
        else if (m[pattern[i] - 'a'] != word) return false;
    }
    return i == len;
}

bool wordPattern2(string pattern, string str)
{
    vector<int> m(26, 0);
    unordered_map<string, int> w;
    istringstream iss(str);
    int len = pattern.length(), i = 0;
    for (string word; iss >> word; ++i)
    {
        if (i >= len || m[pattern[i] - 'a'] != w[word])
            return false;
        m[pattern[i] - 'a'] = w[word] = i + 1;
    }
    return i == len;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

