#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search1(vector<int>& nums, int target)
{
    int L = 0, R = nums.size() - 1;
    while (L <= R)
    {
        int M = L + (R - L) / 2;
        if (target == nums[M]) return M;
        if (target == nums[L]) return L;
        if (target == nums[R]) return R;
        if (nums[M] < nums[R])
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
    return -1;
}

int search2(vector<int>& nums, int target)
{
    if (nums.empty()) return -1;
    int last = nums.size() - 1;
    int L = 0, R = last;
    while (L < R)
    {
        int M = L + (R - L) / 2;
        if (nums[M] < nums[R]) R = M;
        else L = M + 1;
    }
    if (target == nums[last]) return last;
    L = target > nums[last] ? 0 : L;
    R = target > nums[last] ? R - 1 : last;
    while (L <= R)
    {
        int M = L + (R - L) / 2;
        if (target == nums[M]) return M;;
        if (target > nums[M]) L = M + 1;
        else R = M - 1;
    }
    return -1;
}

int search3(vector<int>& nums, int target)
{
    int L = 0, R = nums.size() - 1;
    while (L <= R)
    {
        int M = (L + R) / 2;
        int num = (nums[M] < nums[0]) == (target < nums[0])
                ? nums[M] : target < nums[0] ? INT_MIN : INT_MAX;
        if (num == target) return M;
        if (num < target) L = M + 1;
        else R = M - 1;
    }
    return -1;
}

int search(vector<int>& nums, int target)
{
    if (nums.empty()) return -1;
    auto skip_left  = [&] (int x) { return x >= nums[0] ? numeric_limits<int>::min() : x; };
    auto skip_right = [&] (int x) { return x < nums[0] ? numeric_limits<int>::max() : x; };
    auto adjust = [&] (int x) { return target < nums[0] ? skip_left(x) : skip_right(x); };
    auto it = lower_bound(nums.begin(), nums.end(), target, [&] (int x, int y) { return adjust(x) < adjust(y); });
    return it != nums.end() && *it == target ? it - nums.begin() : -1;
}

int main()
{
//    vector<int> nums{ 10, 12, 14, 2, 4, 6, 8 };
    vector<int> nums{ 1, 3, 1, 1, 1 };
    for (int n : nums)
    {
        cout << search(nums, n) << endl;
    }
    cout << endl;
    cout << search(nums, 11) << endl;
    return 0;
}

