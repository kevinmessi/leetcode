#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void combine(int begin, int end, int k, vector<int> &combination,
             vector<vector<int>> &combinations)
{
    if (k <= 0)
    {
        combinations.push_back(combination);
        return;
    }
    for (int i = begin; i <= end; ++i)
    {
        combination.push_back(i);
        combine(i + 1, end, k - 1, combination, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> combine1(int n, int k)
{
    vector<vector<int>> combinations;
    vector<int> combination;
    combine(1, n, k, combination, combinations);
    return combinations;
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> combinations(1, vector<int>());
    for (int i = 0; i < k; ++i)
    {
        vector<vector<int>> vvi(move(combinations));
        for (auto &combination : vvi)
        {
            vector<int> temp(combination);
            int lower = i > 0 ? combination[i - 1] + 1 : 1;
            int upper = n - k + i + 1;
            for (int j = lower; j <= upper; ++j)
            {
                temp.push_back(j);
                combinations.push_back(temp);
                temp.pop_back();
            }
        }
    }
    return combinations;
}

int main()
{
    PrintMatrix(combine1(6, 3));
    return 0;
}

