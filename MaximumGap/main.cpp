#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maximumGap(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2) return 0;
    auto mm = minmax_element(nums.begin(), nums.end());
    int minimum = *mm.first, maximum = *mm.second;
    int gap = ceil(double(maximum - minimum) / double(n - 1));
    if (gap == 0) return 0;
    vector<int> bucket_min(n, INT_MAX), bucket_max(n, INT_MIN);
    for (int num : nums)
    {
        int i = (num - minimum) / gap;
        bucket_min[i] = min(bucket_min[i], num);
        bucket_max[i] = max(bucket_max[i], num);
    }
    int max_gap = 0, prev = minimum;
    for (int i = 0; i < n; ++i)
    {
        if (bucket_min[i] > bucket_max[i]) continue;
        max_gap = max(max_gap, bucket_min[i] - prev);
        prev = bucket_max[i];
    }
    return max_gap;
}

int main()
{
    vector<int> nums{ 3, 7, 4, 2, 8, 1, INT_MAX };
    cout << maximumGap(nums) << endl;
    return 0;
}
