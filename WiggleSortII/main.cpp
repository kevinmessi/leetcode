#include <algorithm>
#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void wiggleSort1(vector<int> &nums)
{
    vector<int> copy(nums);
    sort(copy.begin(), copy.end());
    for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; --i)
        nums[i] = copy[i & 1 ? k++ : j++];
}

void wiggleSort(vector<int> &nums)
{
    const int len = nums.size();
    auto mid_pos = nums.begin() + len / 2;
    nth_element(nums.begin(), mid_pos, nums.end());
    int median = *mid_pos;
    auto index = [len](int i) { return (1 + i * 2) % (len | 1); };
    int i = 0, j = 0, n = len - 1;
    while (i <= n)
    {
        if (nums[index(i)] > median)
            swap(nums[index(i++)], nums[index(j++)]);
        else if (nums[index(i)] < median)
            swap(nums[index(i)], nums[index(n--)]);
        else
            ++i;
    }
}

int main()
{
    vector<int> nums { 1, 5, 1, 1, 6, 4 };
    wiggleSort(nums);
    PrintVector(nums);
    nums = { 3, 3, 3, 2, 2, 2, 2, 1 };
    wiggleSort(nums);
    PrintVector(nums);
    return 0;
}
