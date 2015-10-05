#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums)
{
    int len = nums.size();
    int i = 1;
    for(;i < len;++i)
    {
        if(nums[i] < nums[i-1]) break;
    }
    if(i == len) return nums[0];
    else return nums[i];
}

int findMin2(vector<int>& nums)
{
    int l = 0, r = nums.size() - 1, m;
    while(l < r)
    {
        m = (l + r) / 2;
        if(nums[m] > nums[r]) l = m + 1;
        else r = m;
    }
    return nums[l];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

