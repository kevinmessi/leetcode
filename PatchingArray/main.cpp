#include <iostream>
#include <vector>

using namespace std;

int minPatches1(vector<int> &nums, int n)
{
    long long upper = 1;
    int patch = 0, i = 0, len = nums.size();
    while (upper <= n)
    {
        if (i >= len || upper < nums[i])
        {
            upper = upper << 1;
            ++patch;
        }
        else upper += nums[i++];
    }
    return patch;
}

int minPatches(vector<int> &nums, int n)
{
    int patch = 0, i = 0, len = nums.size();
    for (long long upper = 1; upper <= n; ++patch)
        upper += (i < len && upper >= nums[i]) ? nums[i++] : upper;
    return patch - i;
}

int main()
{
    vector<int> nums { 1, 3 };
    cout << minPatches(nums, 6) << endl;
    nums = { 1, 5, 10 };
    cout << minPatches(nums, 20) << endl;
    nums = { 1, 2, 2 };
    cout << minPatches(nums, 5) << endl;
    nums = { 1, 2, 4, 13, 43 };
    cout << minPatches(nums, 100) << endl;
    return 0;
}
