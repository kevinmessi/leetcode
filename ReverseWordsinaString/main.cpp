#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void reverseWords1(string &s)
{
    string result;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        if (isspace(s[i])) continue;
        int end = i;
        while (i >= 0 && !isspace(s[i])) --i;
        result.append(s.substr(i + 1, end - i)).append(" ");
    }
    s = result.substr(0, result.length() - 1);
}

void reverseWords2(string &s)
{
    stringstream ss(s);
    string tmp;
    ss >> s;
    while (ss >> tmp) s = tmp + " " + s;
    if (!s.empty() && isspace(s[0])) s = "";
}

void reverseWords(string &s)
{
    reverse(s.begin(), s.end());
    int len = s.length(), tail = 0;
    for (int i = 0; i < len; ++i)
    {
        if (isspace(s[i])) continue;
        int j = i;
        while (i < len && !isspace(s[i]))
            ++i;
        reverse(s.begin() + tail, s.begin() + i);
        tail += (i - j) + 1;
    }
    if (tail > 0) --tail;
    s.erase(tail, len - tail);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

