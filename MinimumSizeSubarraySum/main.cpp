//Given an array of n positive integers and a positive integer s,
//find the minimal length of a subarray of which the sum ≥ s.
//If there isn't one, return 0 instead.
//For example, given the array [2,3,1,2,4,3] and s = 7,
//the subarray [4,3] has the minimal length under the problem constraint.

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums)
{
    return 0;
}

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    cout << minSubArrayLen(7, nums) << endl;
    return 0;
}

