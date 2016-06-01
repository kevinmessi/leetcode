#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> intersect1(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    unordered_map<int, int> map1;
    for (int n : nums1)
        ++map1[n];
    for (int n : nums2)
    {
        if (map1.find(n) != map1.end() && map1[n]-- > 0)
            result.push_back(n);
    }
    return result;
}

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
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
