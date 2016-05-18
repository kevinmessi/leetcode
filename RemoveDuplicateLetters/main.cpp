#include <iostream>
#include <vector>

using namespace std;

string removeDuplicateLetters1(string s)
{
    if (s.empty()) return "";
    int count[26] = { 0 }, len = s.length();
    for (char c : s)
        ++count[c - 'a'];
    int pos = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] < s[pos]) pos = i;
        if (--count[s[i] - 'a'] == 0) break;
    }
    string ss;
    for (int i = pos + 1; i < len; ++i)
    {
        if (s[i] != s[pos])
            ss.append(1, s[i]);
    }
    return s[pos] + removeDuplicateLetters1(ss);
}

string removeDuplicateLetters2(string s)
{
    string result;
    int len = s.length();
    vector<int> table(27, -1);
    table[0] = INT_MAX;
    for (int i = 0; i < len; ++i)
        table[s[i] - 'a' + 1] = i;
    int begin = 0;
    while (begin < len)
    {
        int num = 0;
        for (int i = 1; i <= 26; ++i)
        {
            if (table[i] >= 0 && table[i] < table[num])
                num = i;
        }
        if (num == 0) break;
        char next_char = CHAR_MAX;
        for (int i = begin; i <= table[num]; ++i)
        {
            if (table[s[i] - 'a' + 1] >= 0 && s[i] < next_char)
            {
                begin = i + 1;
                next_char = s[i];
            }
        }
        result.append(1, next_char);
        table[next_char - 'a' + 1] = -1;
    }
    return result;
}

string removeDuplicateLetters(string s)
{
    string result;
    int count[26] = { 0 }, visited[26] = { 0 };
    for (char c : s)
        ++count[c - 'a'];
    for (char c : s)
    {
        --count[c - 'a'];
        if (visited[c - 'a']) continue;
        while (!result.empty() && c < result.back() && count[result.back() - 'a'])
        {
            visited[result.back() - 'a'] = 0;
            result.pop_back();
        }
        result.append(1, c);
        visited[c - 'a'] = 1;
    }
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
