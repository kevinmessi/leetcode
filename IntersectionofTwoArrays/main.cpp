#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> intersection1(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    unordered_set<int> set1(nums1.begin(), nums2.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    for (int n : set1)
    {
        if (set2.find(n) != set2.end())
            result.push_back(n);
    }
    return result;
}

vector<int> intersection2(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> result;
    sort(nums2.begin(), nums2.end());
    for (int n : nums1)
    {
        if (binary_search(nums2.begin(), nums2.end(), n))
            result.insert(n);
    }
    return vector<int>(result.begin(), result.end());
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0, m = nums1.size(), n = nums2.size();
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j]) ++i;
        else if (nums1[i] > nums2[j]) ++j;
        else
        {
            if (result.empty() || result.back() != nums1[i])
                result.push_back(nums1[i]);
            ++i;
            ++j;
        }
    }
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
