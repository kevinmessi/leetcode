#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int longestConsecutive1(vector<int> &nums)
{
    int max_length = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for (int n : nums)
    {
        if (s.find(n) == s.end()) continue;
        s.erase(n);
        int left = n - 1, right = n + 1;
        while (s.find(left) != s.end()) s.erase(left--);
        while (s.find(right) != s.end()) s.erase(right++);
        max_length = max(max_length, right - left - 1);
    }
    return max_length;
}

int longestConsecutive2(vector<int> &nums)
{
    int max_length = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for (int n : nums)
    {
        if (s.find(n - 1) == s.end())
        {
            int right = n + 1;
            while (s.find(right) != s.end()) ++right;
            max_length = max(max_length, right - n);
        }
    }
    return max_length;
}

int longestConsecutive(vector<int> &nums)
{
    int max_length = 0;
    unordered_map<int, int> m;
    for (int n : nums)
    {
        if (m[n]) continue;
        int left = m[n - 1];
        int right = m[n + 1];
        int len = left + right + 1;
        m[n] = 1;
        m[n - left] = len;
        m[n + right] = len;
        max_length = max(max_length, len);
    }
    return max_length;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
