#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> dict;
    unordered_set<char> used;
    int len = s.length();
    for(int i = 0;i < len;++i)
    {
        if(dict.find(s[i]) == dict.end())
        {
            if(used.find(t[i]) != used.end()) return false;
            dict[s[i]] = t[i];
            used.insert(t[i]);
        }
        s[i] = dict[s[i]];
    }
    return s == t;
}

// Only for ASCII.
bool isIsomorphic2(string s, string t)
{
    vector<char> vs(128, 0);
    vector<char> vt(128, 0);
    int len = s.length();
    for(int i = 0;i < len;++i)
    {
        if(vs[s[i]] == 0)
        {
            if(vt[t[i]] != 0 && vt[t[i]] != s[i]) return false;
            vs[s[i]] = t[i];
            vt[t[i]] = s[i];
        }
        s[i] = vs[s[i]];
    }
    return s == t;
}

// Only for ASCII.
bool isIsomorphic3(string s, string t)
{
    vector<int> vs(128, 0);
    vector<int> vt(128, 0);
    int len = s.length();
    for(int i = 0;i < len;++i)
    {
        if(vs[s[i]] != vt[t[i]]) return false;
        vs[s[i]] = i + 1;
        vt[t[i]] = i + 1;
    }
    return true;
}

int main()
{
    cout << isIsomorphic3("ab", "aa") << endl;
    cout << isIsomorphic3("egg", "add") << endl;
    cout << isIsomorphic3("foo", "bar") << endl;
    cout << isIsomorphic3("paper", "title") << endl;
    return 0;
}

