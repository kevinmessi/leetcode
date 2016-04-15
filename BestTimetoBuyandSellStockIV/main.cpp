#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maxProfit1(int k, vector<int> &prices)
{
    int n = prices.size();
    if (k >= n / 2)
    {
        int max_profit = 0;
        for (int i = 1; i < n; ++i)
        {
            int up = prices[i] - prices[i - 1];
            if (up > 0) max_profit += up;
        }
        return max_profit;
    }
    vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
    for (int p : prices)
    {
        for (int i = k; i > 0; --i)
        {
            sell[i] = max(sell[i], buy[i] + p);
            buy[i] = max(buy[i], sell[i - 1] - p);
        }
    }
    return sell[k];
}

int maxProfit2(int k, vector<int> &prices)
{
    int n = prices.size();
    if (k >= n / 2)
    {
        int max_profit = 0;
        for (int i = 1; i < n; ++i)
        {
            int up = prices[i] - prices[i - 1];
            if (up > 0) max_profit += up;
        }
        return max_profit;
    }
    vector<int> dp(n + 1, 0);
    for (int j = 1; j <= k; ++j)
    {
        int temp_max = INT_MIN, pre = dp[0];
        for (int i = 0; i < n; i++)
        {
            int temp = dp[i + 1];
            dp[i + 1] = max(dp[i], prices[i] + temp_max);
            temp_max = max(temp_max, pre - prices[i]);
            pre = temp;
        }
    }
    return dp[n];
}

int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size(), iv, ip = 0;
    vector<int> profits;
    stack<pair<int, int>> vp_pairs;
    while (ip < n)
    {
        for (iv = ip; iv < n - 1 && prices[iv] >= prices[iv + 1]; ++iv)
            ;
        for (ip = iv + 1; ip < n && prices[ip] >= prices[ip - 1]; ++ip)
            ;
        while (!vp_pairs.empty() && prices[iv] < prices[vp_pairs.top().first])
        {
            profits.push_back(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        while (!vp_pairs.empty() && prices[ip - 1] >= prices[vp_pairs.top().second - 1])
        {
            profits.push_back(prices[vp_pairs.top().second - 1] - prices[iv]);
            iv = vp_pairs.top().first;
            vp_pairs.pop();
        }
        vp_pairs.push(make_pair(iv, ip));
    }
    while (!vp_pairs.empty())
    {
        profits.push_back(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
        vp_pairs.pop();
    }
    int len = profits.size();
    if (k >= len) return accumulate(profits.begin(), profits.end(), 0);
    nth_element(profits.begin(), profits.begin() + len - k, profits.end());
    return accumulate(profits.begin() + len - k, profits.end(), 0);
}

int main()
{
    vector<int> prices{ 14, 69, 51, 6, 47, 30, 30, 41, 26, 31, 94, 80, 70, 39, 28, 61, 71 };
    cout << maxProfit(10, prices) << endl;
    return 0;
}
