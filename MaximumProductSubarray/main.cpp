#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums)
{
    int len = nums.size();
    int maximum = nums[0], minimum = nums[0], max_product = nums[0];
    for (int i = 1; i < len; ++i)
    {
        maximum = maximum > 1 ? maximum * nums[i] : nums[i];
        minimum = minimum < 1 ? minimum * nums[i] : nums[i];
        if (nums[i] < 0) swap(maximum, minimum);
        if (maximum > max_product) max_product = maximum;
    }
    return max_product;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

