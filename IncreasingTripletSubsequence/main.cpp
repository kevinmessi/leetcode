#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int one = INT_MAX, two = INT_MAX;
    for (int n : nums)
    {
        if (n > two) return true;
        if (n > one) two = n;
        else one = n;
    }
    return false;
}

int main()
{
    vector<int> nums{ 1, 2, 3, 4, 5 };
    cout << increasingTriplet(nums) << endl;
    nums = { 5, 4, 3, 2, 1 };
    cout << increasingTriplet(nums) << endl;
    return 0;
}

