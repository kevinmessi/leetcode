#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

#include <../toolkit/print.h>

using namespace std;

int findKthLargest1(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int findKthLargest2(vector<int>& nums, int k)
{
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i)
        pq.pop();
    return pq.top();
}

int findKthLargest3(vector<int>& nums, int k)
{
    multiset<int> ms;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        ms.insert(nums[i]);
        if (ms.size() > (size_t)k)
            ms.erase(ms.begin());
    }
    return *ms.begin();
}

int findKthLargest(vector<int>& nums, int begin, int end, int k)
{
    swap(nums[begin + rand() % (end - begin + 1)], nums[end]);
    int j = begin;
    for (int i = begin; i <= end; ++i)
    {
        if (nums[i] >= nums[end])
            swap(nums[j++], nums[i]);
    }
    int x = j - begin;
    if (x > k)
        return findKthLargest(nums, begin, j - 2, k);
    else if (x < k)
        return findKthLargest(nums, j, end, k - x);
    else
        return nums[j - 1];
}

int findKthLargest(vector<int>& nums, int k)
{
    return findKthLargest(nums, 0, nums.size() - 1, k);
}

int main()
{
    vector<int> nums{ 3, 1, 5, 6, 4, 4 };
    cout << findKthLargest(nums, 2) << endl;
    return 0;
}

