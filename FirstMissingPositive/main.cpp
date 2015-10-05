//Given an unsorted integer array, find the first missing positive integer.
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//Your algorithm should run in O(n) time and uses constant space.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    int n = nums.size();
    for(int i = 0;i < n;++i)
    {
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for(int i = 0;i < n;++i)
    {
        if(nums[i] != i + 1) return i + 1;
    }
    return n + 1;
}

int firstMissingPositive1(vector<int>& nums)
{
    int len = nums.size();
    vector<int> positives;
    for(int i = 1;i <= len + 1;++i)
    {
        positives.push_back(i);
    }
    for(int i = 0;i < len;++i)
    {
        if(nums[i] > 0 && nums[i] <= len)
        {
            positives[nums[i] - 1] = 0;
        }
    }
    int i = 0;
    while(positives[i] <= 0)
    {
        ++i;
    }
    return positives[i];
}

int firstMissingPositive2(vector<int>& nums)
{
    int n = nums.size();
    for(int i = 0;i < n;++i)
    {
        if(nums[i] <= 0 || nums[i] > n)
        {
            nums[i] = n + 1;
        }
    }
    for(int i = 0;i < n;++i)
    {
        int x = abs(nums[i]);
        if(x - 1 < n && nums[x-1] > 0)
        {
            nums[x-1] = -nums[x-1];
        }
    }
    for(int i = 0;i < n;++i)
    {
        if(nums[i] > 0) return i + 1;
    }
    return n + 1;
}

int main()
{
    vector<int> v = {1,2,0};
    cout << firstMissingPositive(v) << endl;
    return 0;
}
