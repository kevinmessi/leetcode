#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintArray(vector<int> v)
{
    int l = v.size();
    for(int i = 0;i < l;i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void PrintMatrix(vector<vector<int>> m)
{
    int r = m.size();
    for(int i = 0;i < r;i++)
    {
        PrintArray(m[i]);
    }
}

void permute_recursive(vector<int>& nums, int p, vector<vector<int>>& results)
{
    int len = nums.size();
    if(p == len - 1) results.push_back(nums);
    else
    {
        for(int i = p;i < len;++i)
        {
            swap(nums[i], nums[p]);
            permute_recursive(nums, p + 1, results);
            swap(nums[i], nums[p]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> results;
    permute_recursive(nums, 0, results);
    return results;
}

vector<vector<int>> permute2(vector<int>& nums)
{
    vector<vector<int>> v(1,vector<int>());
    for (size_t i = 0; i < nums.size(); ++i)
    {
        vector<vector<int>> tv(move(v));
        for (size_t j = 0; j < tv.size(); ++j)
        {
            for (size_t k = 0; k <= tv[0].size(); ++k)
            {
                vector<int> tmp(tv[j]);
                tmp.insert(tmp.begin() + k,nums[i]);
                v.push_back(move(tmp));
            }
        }
    }
    return v;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    PrintArray(v);
    cout << endl;
    PrintMatrix(permute(v));
    return 0;
}

