#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void nextPermutation(vector<int>& nums)
{
    int len = nums.size();
    if (len < 2) return;
    int p, q;
    for (p = len - 2; p >= 0 && nums[p] >= nums[p + 1]; --p)
        ;
    for (int i = p + 1, j = len - 1; i < j; ++i, --j)
        swap(nums[i], nums[j]);
    if (p < 0) return;
    for (q = p + 1; q < len && nums[p] >= nums[q]; ++q)
        ;
    swap(nums[p], nums[q]);
}

int main()
{
    vector<int> nums{ 1, 2, 3 };
    PrintVector(nums);
    nextPermutation(nums);
    PrintVector(nums);
    return 0;
}

