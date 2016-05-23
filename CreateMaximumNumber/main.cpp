#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

bool is_greater(vector<int> &nums1, int i, vector<int> &nums2, int j)
{
    int len1 = nums1.size(), len2 = nums2.size();
    for (; i < len1 && j < len2 && nums1[i] == nums2[j]; ++i, ++j)
        ;
    return i < len1 && (j == len2 || nums1[i] > nums2[j]);
}

void maxNumber(vector<int> &nums, int k, vector<int> &max_nums)
{
    int len = nums.size();
    max_nums.resize(k);
    for (int i = 0, j = 0; i < len; ++i)
    {
        while (k - j < len - i && j > 0 && max_nums[j - 1] < nums[i])
            --j;
        if (j < k) max_nums[j++] = nums[i];
    }
}

void merge(vector<int> &nums1, vector<int> &nums2, vector<int> &output)
{
    int len1 = nums1.size(), len2 = nums2.size();
    output.resize(len1 + len2);
    for (int i = 0, j = 0, kk = 0; i < len1 || j < len2; ++kk)
        output[kk] = is_greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
}

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int len1 = nums1.size(), len2 = nums2.size();
    vector<int> number, candidate, max1, max2;
    for (int i = max(0, k - len2); i <= k && i <= len1; ++i)
    {
        maxNumber(nums1, i, max1);
        maxNumber(nums2, k - i, max2);
        merge(max1, max2, candidate);
        if (is_greater(candidate, 0, number, 0))
            number = candidate;
    }
    return number;
}

int main()
{
    vector<int> nums1, nums2;

    nums1 = { 3, 4, 6, 5 };
    nums2 = { 9, 1, 2, 5, 8, 3 };
    PrintVector(maxNumber(nums1, nums2, 5)); // [9, 8, 6, 5, 3]

    nums1 = { 6, 7 };
    nums2 = { 6, 0, 4 };
    PrintVector(maxNumber(nums1, nums2, 5)); // [6, 7, 6, 0, 4]

    nums1 = { 3, 9 };
    nums2 = { 8, 9 };
    PrintVector(maxNumber(nums1, nums2, 3)); // [9, 8, 9]

    return 0;
}
