#include <iostream>
#include <set>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

bool canJump(vector<int>& nums)
{
    int n = nums.size(), i = 0;
    for (int utmost = 0; i < n && i <= utmost; ++i)
        utmost = max(utmost, i + nums[i]);
    return i == n;
}

int main()
{
    vector<int> v = {0};
    cout << canJump(v) << endl;
    return 0;
}

