#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.empty()) return 0;
    int buy = -prices[0], sell = 0, pre_buy = 0, pre_sell = 0;
    for (int p : prices)
    {
        pre_buy = buy;
        buy = max(pre_sell - p, buy);
        pre_sell = sell;
        sell = max(pre_buy + p, sell);
    }
    return sell;
}

int main()
{
    vector<int> prices{ 1, 2, 3, 0, 2 };
    cout << maxProfit(prices) << endl;
    return 0;
}

