#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    int len = nums.size();
    for(int i = 0;i < len;++i)
    {
        while (nums[i] < len && nums[i] != nums[nums[i]])
        {
            swap(nums[i], nums[nums[i]]);
        }
    }
    for (int i = 0;i < len;++i)
    {
        if (nums[i] != i) return i;
    }
    return len;
}

int missingNumber2(vector<int>& nums)
{
    int len = nums.size();
    int sum = 0;
    for(int i = 0;i < len;++i) sum += nums[i];
    return len * (len + 1) / 2 - sum;
}

int missingNumber3(vector<int>& nums)
{
    int len = nums.size();
    int result = len;
    for(int i = 0;i < len;++i) result = result ^ i ^ nums[i];
    return result;
}

int main()
{
    vector<int> nums = {0,1,3};
    cout << missingNumber3(nums) << endl;
    return 0;
}

