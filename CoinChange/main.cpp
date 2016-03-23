#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int coinChange1(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    vector<int> nums(amount + 1, amount + 1);
    nums[0] = 0;
    int len = coins.size();
    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < len && coins[j] <= i; ++j)
            nums[i] = min(nums[i], nums[i - coins[j]] + 1);
    }
    return nums[amount] > amount ? -1 : nums[amount];
}

int coinChange2(vector<int> &coins, int amount)
{
    vector<int> nums(amount + 1, amount + 1);
    nums[0] = 0;
    for (int c : coins)
    {
        for (int i = c; i <= amount; ++i)
            nums[i] = min(nums[i], nums[i - c] + 1);
    }
    return nums[amount] > amount ? -1 : nums[amount];
}

int coinChange3(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    int num = 0, len = coins.size();
    queue<int> q;
    q.push(amount);
    vector<int> visited(amount + 1, 0);
    visited[amount] = 1;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            amount = q.front();
            if (amount == 0) return num;
            for (int i = 0; i < len && coins[i] <= amount; ++i)
            {
                if (!visited[amount - coins[i]])
                {
                    q.push(amount - coins[i]);
                    visited[amount - coins[i]] = 1;
                }
            }
            q.pop();
        }
        ++num;
    }
    return -1;
}

void dfs(vector<int> &coins, int idx, int amount, int count, int &num)
{
    if (idx < 0) return;
    int m = amount / coins[idx];
    if (count + m >= num) return;
    for (int i = m; i >= 0; --i)
    {
        int remain = amount - coins[idx] * i;
        int new_count = count + i;
        if (remain == 0)
            num = new_count;
        else
            dfs(coins, idx - 1, remain, new_count, num);
    }
}

int coinChange(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    int num = amount + 1;
    dfs(coins, coins.size() - 1, amount, 0, num);
    return num > amount ? -1 : num;
}

int main()
{
    vector<int> coins{ 1, 2, 5 };
    cout << coinChange(coins, 11) << endl;
    return 0;
}

