#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums)
{
    int n = nums.size() - 1;
    int left = 1, right = n;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        int count = 0;
        for (int i = 0;i <= n;++i)
        {
            if (nums[i] <= mid) ++count;
        }
        if (count > mid) right = mid;
        else left = mid + 1;
    }
    return left;
}

int findDuplicate2(vector<int>& nums)
{
    assert(nums.size() > 1);
    int slow = 0, fast = 0;
    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) break;
    }
    int head = 0;
    while (true)
    {
        slow = nums[slow];
        head = nums[head];
        if (slow == head) break;
    }
    return slow;
}

int main()
{
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate2(nums) << endl;
    return 0;
}

