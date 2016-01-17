#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> range(2, -1);
    int L = 0, R = nums.size() - 1;
    while (L <= R)
    {
        int M = (R - L) / 2 + L;
        if (nums[M] < target) L = M + 1;
        else R = M - 1;
    }
    if (nums[L] == target) range[0] = L;
    else return range;
    R = nums.size() - 1;
    while (L <= R)
    {
        int M = (R - L) / 2 + L;
        if (nums[M] > target) R = M - 1;
        else L = M + 1;
    }
    range[1] = R;
    return range;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

