/*
 * Given an array of size n, find the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 * Another Method:
 * Runtime: O(n) — Bit manipulation:
 * We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers.
 * Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal).
 * The majority number’s ith bit must be the one bit that has the greater count.
 */

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &num)
{
    int cnt = 0, res, len = num.size();
    for (int i = 0; i < len; ++i)
    {
        if (cnt == 0) res = num[i];
        if (res == num[i]) ++cnt;
        else --cnt;
        cout << "res:" << res << " cnt:" << cnt << endl;
    }
    return res;
}

int main()
{
    vector<int> a = {3,3,3,2,3,4,3,4,3};
    cout << majorityElement(a) << endl;
    return 0;
}
