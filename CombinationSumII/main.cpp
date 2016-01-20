#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void combinationSum2(vector<int>& candidates, int target, int begin,
                     vector<int> &combination, vector<vector<int>> &combinations)
{
    if (target == 0)
    {
        combinations.push_back(combination);
        return;
    }
    for (int i = begin; i < (int)candidates.size(); ++i)
    {
        if (target < candidates[i])
            return;
        if (i > begin && candidates[i] == candidates[i - 1])
            continue;
        combination.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], i + 1, combination, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> combinations;
    vector<int> combination;
    combinationSum2(candidates, target, 0, combination, combinations);
    return combinations;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

