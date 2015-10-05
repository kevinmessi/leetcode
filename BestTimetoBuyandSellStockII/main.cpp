/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
 * However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit2(vector<int>& prices)
{
    int len = prices.size();
    if(len < 2) return 0;
    int profit = 0;
    int buy = prices[0];
    for(int i = 1;i < len;++i)
    {
        if(prices[i] < prices[i-1])
        {
            profit += prices[i-1] - buy;
            buy = prices[i];
        }
    }
    profit += prices[len-1] - buy;
    return profit;
}

int maxProfit(vector<int>& prices)
{
    int len = prices.size();
    int profit = 0;
    int tmp;
    for(int i = 1;i < len;++i)
    {
        tmp = prices[i] - prices[i-1];
        if(tmp > 0) profit+= tmp;
    }
    return profit;
}

int main()
{
    vector<int> p = {1,2,4,3,1,3,4};
    cout << maxProfit(p) << endl;
    return 0;
}

