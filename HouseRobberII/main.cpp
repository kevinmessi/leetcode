#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums)
{
    int len = nums.size();
    int pre2 = 0, pre1 = 0, money1 = 0, money2 = 0;
    for (int i = 0; i < len - 1; ++i)
    {
        money1 = max(nums[i] + pre2, pre1);
        pre2 = pre1;
        pre1 = money1;
    }
    pre2 = 0, pre1 = 0;
    for (int i = 1; i < len - 2; ++i)
    {
        money2 = max(nums[i] + pre2, pre1);
        pre2 = pre1;
        pre1 = money2;
    }
    return max(money1, money2 + (len > 0 ? nums[len - 1] : 0));
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

