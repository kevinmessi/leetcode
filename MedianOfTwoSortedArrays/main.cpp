//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    int b1 = 0, e1 = m - 1, b2 = 0, e2 = n - 1;
    return (m + n) / 2.0;
}

int main()
{
    vector<int> nums1 = { 6, 14, 30, 30, 41, 47, 51, 69 };
    vector<int> nums2 = { 7, 18, 44, 50, 96, };
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

