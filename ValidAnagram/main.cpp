#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t)
{
    int ns = s.length(), nt = t.length();
    if(ns != nt) return false;
    vector<int> vs(26, 0);
    for(int i = 0;i < ns;++i)
    {
        ++vs[s[i] - 'a'];
        --vs[t[i] - 'a'];
    }
    for(int i = 0;i < 26;++i)
    {
        if(vs[i]) return false;
    }
    return true;
}

int main()
{
    cout << isAnagram("anagram", "nagaram") << endl;
    return 0;
}

