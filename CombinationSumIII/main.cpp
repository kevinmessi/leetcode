#include <iostream>
#include <vector>

using namespace std;

void combinationSum3(int m, int k, int n, vector<int> &combination, vector<vector<int>> &combinations)
{
    if (k == 0 || m > 9)
    {
        if (k == 0 && n == 0) combinations.push_back(combination);
        return;
    }
    for (int i = m; i <= 9; ++i)
    {
        combination.push_back(i);
        combinationSum3(i + 1, k - 1, n - i, combination, combinations);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum31(int k, int n)
{
    vector<vector<int>> combinations;
    vector<int> combination;
    combinationSum3(1, k, n, combination, combinations);
    return combinations;
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> combinations;
    vector<int> combination(k, 0);
    int i = 0, s = 0;
    while (i >= 0)
    {
        ++combination[i];
        ++s;
        if (combination[i] > 9 || s > n)
        {
            s -= combination[i];
            --i;
        }
        else if (i == k - 1)
        {
            if (s == n) combinations.push_back(combination);
        }
        else
        {
            s += combination[i];
            combination[i + 1] = combination[i];
            ++i;
        }
    }
    return combinations;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

