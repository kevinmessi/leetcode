#include <iostream>
#include <vector>

using namespace std;

int numDistinct1(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> nums(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i)
        nums[i][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            nums[i][j] = nums[i - 1][j];
            if (s[i - 1] == t[j - 1])
                nums[i][j] += nums[i - 1][j - 1];
        }
    }
    return nums[n][m];
}

int numDistinct2(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> nums(m + 1, 0);
    nums[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int pre = 1;
        for (int j = 1; j <= m; ++j)
        {
            int temp = nums[j];
            if (s[i - 1] == t[j - 1])
                nums[j] += pre;
            pre = temp;
        }
    }
    return nums[m];
}

int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    if (n < m) return 0;
    vector<int> nums(m + 1, 0);
    nums[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = min(m, i); j >= 1; --j)
        {
            if (s[i - 1] == t[j - 1])
                nums[j] += nums[j - 1];
        }
    }
    return nums[m];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

