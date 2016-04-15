#include <iostream>
#include <vector>

using namespace std;

int maxProfit1(vector<int> &prices)
{
    int n = prices.size(), max_profit = 0;
    vector<int> forward(n, 0), backward(n, 0);
    for (int i = n - 2, profit = 0; i >= 0; --i)
    {
        if (profit > 0) profit += prices[i + 1] - prices[i];
        else profit = prices[i + 1] - prices[i];
        backward[i] = max(backward[i + 1], profit);
    }
    for (int i = 1, profit = 0; i < n; ++i)
    {
        if (profit > 0) profit += prices[i] - prices[i - 1];
        else profit = prices[i] - prices[i - 1];
        forward[i] = max(forward[i - 1], profit);
        max_profit = max(max_profit, forward[i] + backward[i]);
    }
    return max_profit;
}

int maxProfit2(vector<int> &prices)
{
    int k = 2, n = prices.size();
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= k; ++j)
    {
        int temp = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            dp[j][i + 1] = max(dp[j][i], prices[i] + temp);
            temp = max(temp, dp[j - 1][i] - prices[i]);
        }
    }
    return dp[k][n];
}

int maxProfit(vector<int> &prices)
{
    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    for (int p : prices)
    {
        sell2 = max(sell2, buy2 + p);
        buy2 = max(buy2, sell1 - p);
        sell1 = max(sell1, buy1 + p);
        buy1 = max(buy1, -p);
    }
    return sell2;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

