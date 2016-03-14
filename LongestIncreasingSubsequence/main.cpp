#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS1(vector<int> &nums)
{
    int lis = 0, len = nums.size();
    vector<int> v(len, 1);
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
                v[i] = max(v[i], v[j] + 1);
        }
        lis = max(lis, v[i]);
    }
    return lis;
}

int lengthOfLIS(vector<int> &nums)
{
    int lis = 0;
    vector<int> tail(nums.size());
    for (int n : nums)
    {
        int L = 0, R = lis;
        while (L < R)
        {
            int M = L + (R - L) / 2;
            if (tail[M] >= n) R = M;
            else L = M + 1;
        }
        tail[L] = n;
        if (L == lis) ++lis;
    }
    return lis;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

