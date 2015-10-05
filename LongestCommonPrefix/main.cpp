#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(string s1, string s2)
{
    string s = "";
    int len = min(s1.size(),s2.size());
    for(int i = 0;i < len;++i)
    {
        if(s1[i] == s2[i]) s += s1[i];
        else break;
    }
    return s;
}

string longestCommonPrefix(vector<string> &strs, int p, int q)
{
    if(p == q) return strs[p];
    int m = (p+q)/2;
    return longestCommonPrefix(longestCommonPrefix(strs, p, m), longestCommonPrefix(strs, m+1, q));
}

string longestCommonPrefix(vector<string> &strs)
{
    int len = strs.size();
    if(len <= 0) return "";
    return longestCommonPrefix(strs, 0, len - 1);
}

//string longestCommonPrefix(vector<string> &strs)
//{
//    int len = strs.size();
//    if(len <= 0) return "";
//    string s = strs[0];
//    for(int i = 1;i < len;++i)
//    {
//        s = longestCommonPrefix(strs[i], s);
//    }
//    return s;
//}

int main()
{
    vector<string> v = {"abcccccccc","abc","abcde"};
    cout << longestCommonPrefix(v) << endl;
//    cout << longestCommonPrefix("aabn", "aaa") << endl;
    return 0;
}

