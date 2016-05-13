#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow1(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0) return{};
    deque<int> dq;
    vector<int> window(n - k + 1);
    for (int i = 0; i < n; ++i)
    {
        if (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) window[i - k + 1] = nums[dq.front()];
    }
    return window;
}

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0) return{};
    vector<int> window(n - k + 1), left_max(n), right_max(n);
    left_max[0] = nums[0], right_max[n - 1] = nums[n - 1];
    for (int i = 1, j = n - 2; i < n; ++i, --j)
    {
        left_max[i] = i % k == 0 ? nums[i] : max(left_max[i - 1], nums[i]);
        right_max[j] = j % k == 0 ? nums[j] : max(right_max[j + 1], nums[j]);
    }
    for (int i = 0; i <= n - k; ++i)
        window[i] = max(left_max[i + k - 1], right_max[i]);
    return window;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
