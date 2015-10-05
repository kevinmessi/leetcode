#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
    int len = nums.size();
    if(len < 1) return 0;
    vector<int> m;
    m.push_back(nums[0]);
    m.push_back(max(nums[0], nums[1]));
    for(int i = 2;i < len;++i)
    {
        m.push_back(max(nums[i] + m[i-2], m[i-1]));
    }
    return m[len-1];
}

int rob2(vector<int>& nums)
{
    int len = nums.size();
    int last_2 = 0;
    int last_1 = 0;
    int money = 0;
    for(int i = 0;i < len;++i)
    {
        money = max(nums[i] + last_2, last_1);
        last_2 = last_1;
        last_1 = money;
    }
    return money;
}

int main()
{
    vector<int> v = {7,2,3,1,8,6,7};
    cout << rob2(v) << endl;
    return 0;
}

