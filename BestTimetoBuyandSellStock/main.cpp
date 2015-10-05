#include <iostream>
#include <vector>

using namespace std;

int maxProfit2(vector<int>& prices)
{
    vector<int> spread;
    int len = prices.size();
    if(len < 2) return 0;
    for(int i = 1;i < len;++i)
    {
        spread.push_back(prices[i] - prices[i-1]);
    }
    int max = spread[0];
    int sum = spread[0];
    for(int i = 1;i < len - 1;++i)
    {
        if(sum > 0) sum += spread[i];
        else sum = spread[i];
        if(sum > max) max = sum;
    }
    if(max < 0) return 0;
    return max;
}

int maxProfit(vector<int>& prices)
{
    int len = prices.size();
    if(len < 2) return 0;
    int max = 0;
    int sum = 0;
    for(int i = 1;i < len;++i)
    {
        if(sum > 0) sum += prices[i] - prices[i-1];
        else sum = prices[i] - prices[i-1];
        if(sum > max) max = sum;
    }
    return max;
}

int main()
{
    vector<int> v = {1,2};
    cout << maxProfit(v) << endl;
    return 0;
}

