#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsNearbyAlmostDuplicate1(vector<int> &nums, int k, int t)
{
    set<int> window;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        if (i > k) window.erase(nums[i - k - 1]);
        auto pos = window.lower_bound(nums[i] - t);
        if (pos != window.end() && *pos - nums[i] <= t) return true;
        window.insert(nums[i]);
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    if (t < 0) return false;
    unordered_map<long long, long long> table;
    int len = nums.size();
    auto calculate_bucket = [t](long long n){ return (n - INT_MIN) / ((long long)t + 1); };
    for (int i = 0; i < len; ++i)
    {
        if (i > k)
            table.erase(calculate_bucket(nums[i - k - 1]));
        long long bucket = calculate_bucket(nums[i]);
        if (table.find(bucket) != table.end())
            return true;
        if (table.find(bucket - 1) != table.end() && nums[i] - table[bucket - 1] <= t)
            return true;
        if (table.find(bucket + 1) != table.end() && table[bucket + 1] - nums[i] <= t)
            return true;
        table[bucket] = nums[i];
    }
    return false;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
