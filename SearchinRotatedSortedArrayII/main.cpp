#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target)
{
    int n = nums.size();
    int L = 0, R = n - 1;
    while (L <= R)
    {
        int M = L + (R - L) / 2;
        if (target == nums[M]) return true;
        if (target == nums[L]) return true;
        if (target == nums[R]) return true;
        if (nums[M] == nums[R])
        {
            while (R >= 0 && nums[R] == nums[M]) --R;
            while (L < n && nums[L] == nums[M]) ++L;
        }
        else if (nums[M] < nums[R])
        {
            if (target > nums[M] && target < nums[R]) L = M + 1;
            else R = M - 1;
        }
        else
        {
            if (target < nums[M] && target > nums[L]) R = M - 1;
            else L = M + 1;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = { 1, 1, 1, 1, 1 };
    for (int n : nums)
    {
        cout << search(nums, n) << endl;
    }
    cout << endl;
    cout << search(nums, 11) << endl;
    return 0;
}

