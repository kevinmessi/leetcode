#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &nums)
{
    int L = 0, R = nums.size() - 1;
    while (L < R)
    {
        int M = L + (R - L) / 2;
        if (nums[M] == nums[R])
        {
            if (nums[M] < nums[L]) R = M;
            else --R;
        }
        else if (nums[M] < nums[R]) R = M;
        else L = M + 1;
    }
    return nums[L];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
