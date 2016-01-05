//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    if (m + n == 0) return 0;
    if (m > n) return findMedianSortedArrays(nums2, nums1);
    int imin = 0, imax = m, half_len = (m + n + 1) / 2;
    int i, j;
    double median;
    while(imin <= imax)
    {
        i = (imin + imax) / 2;
        j = half_len - i;
        if (i > 0 && j < n && nums1[i-1] > nums2[j]) imax = i - 1;
        else if (j > 0 && i < m && nums2[j-1] > nums1[i]) imin = i + 1;
        else
        {
            if (i == 0) median = nums2[j-1];
            else if (j == 0) median = nums1[i-1];
            else median = max(nums1[i-1], nums2[j-1]);
            if ((m + n) % 2 == 0)
            {
                if (i == m) median = (median + nums2[j]) / 2.0;
                else if (j == n) median = (median + nums1[i]) / 2.0;
                else median = (median + min(nums1[i], nums2[j])) / 2.0;
            }
            break;
        }
    }
    return median;
}

int main()
{
    vector<int> nums1 = { 2 };
    vector<int> nums2 = { };
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

// https://leetcode.com/discuss/15790/share-my-o-log-min-m-n-solution-with-explanation
