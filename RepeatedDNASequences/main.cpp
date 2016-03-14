#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> findRepeatedDnaSequences1(string s)
{
    vector<string> sequences;
    unordered_map<string, int> ss;
    int end = s.size() - 10;
    for (int i = 0; i <= end; ++i)
    {
        string sub = s.substr(i, 10);
        if (++ss[sub] == 2) sequences.push_back(sub);
    }
    return sequences;
}

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> sequences;
    unordered_map<int, int> ss;
    int len = s.size(), key = 0;
    for (int i = 0; i < len; ++i)
    {
        key = ((key << 3) & 0x3fffffff) | (s[i] & 7);
        if (++ss[key] == 2) sequences.push_back(s.substr(i - 9, 10));
    }
    return sequences;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

