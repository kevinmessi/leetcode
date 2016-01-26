#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void permuteUnique1(vector<int>& nums, int begin, vector<vector<int>> &permutations)
{
    int len = nums.size();
    if (begin >= len)
    {
        permutations.push_back(nums);
        return;
    }
    unordered_set<int> nset;
    for (int i = begin; i < len; ++i)
    {
        if (nset.find(nums[i]) != nset.end()) continue;
        nset.insert(nums[i]);
        swap(nums[begin], nums[i]);
        permuteUnique1(nums, begin + 1, permutations);
        swap(nums[begin], nums[i]);
    }
}

vector<vector<int>> permuteUnique1(vector<int>& nums)
{
    vector<vector<int>> permutations;
    permuteUnique1(nums, 0, permutations);
    return permutations;
}

void permuteUnique(vector<int> nums, int begin, vector<vector<int>> &permutations)
{
    int len = nums.size();
    if (begin >= len)
    {
        permutations.push_back(nums);
        return;
    }
    permuteUnique(nums, begin + 1, permutations);
    for (int i = begin + 1; i < len; ++i)
    {
        if (nums[i] == nums[begin]) continue;
        swap(nums[begin], nums[i]);
        permuteUnique(nums, begin + 1, permutations);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> permutations;
    permuteUnique(nums, 0, permutations);
    return permutations;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

