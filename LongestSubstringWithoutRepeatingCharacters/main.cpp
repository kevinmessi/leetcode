#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring1(string s)
{
    int longest_len = 0;
    int len = s.size();
    for (int begin = 0, end = 0; end < len; ++end)
    {
        if (end - begin + 1 > longest_len)
            longest_len = end - begin + 1;
        for (int i = end; i >= begin; --i)
        {
            if (s[i] == s[end + 1])
            {
                begin = i + 1;
                break;
            }
        }
    }
    return longest_len;
}

int lengthOfLongestSubstring2(string s)
{
    int longest_len = 0;
    int len = s.size();
    unordered_map<char, int> sub;
    for (int begin = 0, end = -1; end < len; ++end)
    {
        if (end - begin + 1 > longest_len)
            longest_len = end - begin + 1;
        auto search = sub.find(s[end + 1]);
        if(search != sub.end() && search->second >= begin)
            begin = search->second + 1;
        sub[s[end + 1]] = end + 1;
    }
    return longest_len;
}

int lengthOfLongestSubstring(string s)
{
    int longest_len = 0;
    int len = s.size();
    vector<int> sub(256, -1);
    for (int begin = 0, end = -1; end < len; ++end)
    {
        if (end - begin + 1 > longest_len)
            longest_len = end - begin + 1;
        if (sub[s[end + 1]] >= begin)
            begin = sub[s[end + 1]] + 1;
        sub[s[end + 1]] = end + 1;
    }
    return longest_len;
}

int main()
{
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("helloworld") << endl;
    return 0;
}

