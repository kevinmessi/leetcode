//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    return (m + n) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

