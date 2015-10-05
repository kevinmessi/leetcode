#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums)
{
    int len = nums.size();
    if(nums[0] > nums[1]) return 0;
    for(int i = 1;i < len-1;++i)
    {
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
    }
    if(nums[len-1] > nums[len-2]) return len - 1;
}

int findPeakElement2(vector<int>& nums)
{
    int l = 0, r = nums.size() - 1, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if(nums[m] > nums[m+1]) r = m;
        else l = m + 1;
    }
    return l;
}

int main()
{
    vector<int> v = {1, 2, 3, 1};
    cout << findPeakElement2(v) << endl;
    return 0;
}

