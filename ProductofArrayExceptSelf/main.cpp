#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

vector<int> productExceptSelf1(vector<int>& nums)
{
    int len = nums.size();
    vector<int> products(len);
    products[0] = 1;
    vector<int> reverse(len);
    reverse[0] = 1;
    for (int i = 1;i < len; ++i)
    {
        products[i] = products[i - 1] * nums[i - 1];
        reverse[i] = reverse[i - 1] * nums[len - i];
    }
    for (int i = 0; i < len; ++i)
        products[i] *= reverse[len - i - 1];
    return products;
}

vector<int> productExceptSelf2(vector<int>& nums)
{
    int len = nums.size();
    vector<int> products(len);
    products[0] = 1;
    for (int i = 1;i < len; ++i)
        products[i] = products[i - 1] * nums[i - 1];
    int reverse = 1;
    for (int i = len - 1; i >= 0; --i)
    {
        products[i] *= reverse;
        reverse *= nums[i];
    }
    return products;
}

vector<int> productExceptSelf(vector<int>& nums)
{
    int len = nums.size();
    int left = 1, right = 1;
    vector<int> products(len, 1);
    for (int i = 0; i < len; ++i)
    {
        products[i] *= left;
        left *= nums[i];
        products[len - i - 1] *= right;
        right *= nums[len - i - 1];
    }
    return products;
}

int main()
{
    vector<int> nums{ 1, 2, 3, 4 };
    PrintVector(productExceptSelf(nums));
    return 0;
}

