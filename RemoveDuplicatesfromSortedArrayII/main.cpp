#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates1(vector<int>& nums)
{
    int len = nums.size();
    if (len <= 2) return len;
    int m = 2, temp = nums[0];
    for (int i = 2; i < len; ++i)
    {
        if (nums[i] != temp)
        {
            temp = nums[i - 1];
            nums[m++] = nums[i];
        }
        else
        {
            temp = nums[i - 1];
        }
    }
    return m;
}

int removeDuplicates2(vector<int>& nums)
{
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; ++i)
    {
        if (nums[i] == nums[i - 2 - count])
            count++;
        else
            nums[i - count] = nums[i];
    }
    return n - count;
}

int removeDuplicates(vector<int>& nums)
{
    int i = 0;
    for (int n : nums)
        if (i < 2 || n != nums[i - 2])
            nums[i++] = n;
    return i;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

