#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int threeSumClosest1(vector<int>& nums, int target)
{
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int lower = nums[0] + nums[1] + nums[2];
    if (lower >= target) return lower;
    int upper = nums[len - 1] + nums[len - 2] + nums[len - 3];
    if (upper <= target) return upper;
    for (int i = len - 1; i >= 2; --i)
    {
        int left = 0, right = i - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) return target;
            if (sum > target)
            {
                upper = min(upper, sum);
                --right;
            }
            else
            {
                lower = max(lower, sum);
                ++left;
            }
        }
    }
    return upper - target < target - lower ? upper : lower;
}

int threeSumClosest(vector<int>& nums, int target)
{
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];
    for (int i = len - 1; i >= 2; --i)
    {
        int left = 0, right = i - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) return target;
            if (abs(ans - target) > abs(sum - target)) ans = sum;
            sum > target ? --right : ++left;
        }
    }
    return ans;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

