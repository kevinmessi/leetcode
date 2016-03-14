#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> result;
    int len = nums.size();
    int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < len; ++i)
    {
        if (nums[i] == num1) ++count1;
        else if (nums[i] == num2) ++count2;
        else if (count1 == 0) num1 = nums[i], count1 = 1;
        else if (count2 == 0) num2 = nums[i], count2 = 1;
        else --count1, --count2;
    }
    count1 = 0, count2 = 0;
    for (int i = 0; i < len; ++i)
    {
        if (nums[i] == num1) ++count1;
        else if (nums[i] == num2) ++count2;
    }
    if (count1 > len / 3) result.push_back(num1);
    if (count2 > len / 3) result.push_back(num2);
    return result;
}

int main()
{
    vector<int> nums { 1, 2, 3, 4 };
    PrintVector(majorityElement(nums));
    return 0;
}

