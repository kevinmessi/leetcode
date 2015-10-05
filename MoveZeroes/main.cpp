#include "../toolkit/print.h"
#include <iostream>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    for(size_t i = 0, j = 0;i < nums.size();++i)
    {
        if(nums[i] != 0) swap(nums[i], nums[j++]);
    }
}

void moveZeroes2(vector<int>& nums)
{
    fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
}

int main()
{
    vector<int> nums = {8, 0, 0, 1, 0, 3, 12};
    PrintVector(nums);
    moveZeroes2(nums);
    PrintVector(nums);
    return 0;
}

