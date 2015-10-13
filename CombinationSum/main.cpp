#include <iostream>
#include <algorithm>

#include "../toolkit/print.h"

using namespace std;

void solve(vector<int> &candidates, int n, int target, vector<int> &solution,
           vector<vector<int>> &combinations)
{
    if (target == 0)
    {
        combinations.push_back(solution);
        return;
    }
    if (n == (int)candidates.size() || target < candidates[n])
        return;
    solution.push_back(candidates[n]);
    solve(candidates, n, target - candidates[n], solution, combinations);
    solution.pop_back();
    solve(candidates, n + 1, target, solution, combinations);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> combinations;
    vector<int> solution;
    sort(candidates.begin(), candidates.end());
    solve(candidates, 0, target, solution, combinations);
    return combinations;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<vector<int>>> results(target + 1, vector<vector<int>>());
    results[0].push_back(vector<int>());
    for (auto &candidate : candidates)
    {
        for (int j = candidate; j <= target; ++j)
        {
            vector<vector<int>> combinations = results[j - candidate];
            if (combinations.size() > 0)
            {
                for (auto &temp : combinations)
                {
                    temp.push_back(candidate);
                }
                results[j].insert(results[j].end(), combinations.begin(), combinations.end());
            }
        }
    }
    return results[target];
}

int main()
{
    vector<int> candidates = {2,3,6,7};
    PrintMatrix(combinationSum2(candidates, 9));
    return 0;
}

