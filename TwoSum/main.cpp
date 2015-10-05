#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void PrintVector(vector<int> v)
{
    for(unsigned int i = 0;i < v.size();++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> n(numbers);
    int len = numbers.size();
    sort(n.begin(),n.end());
    int i = 0,j = len - 1;
    while(i<j)
    {
        if(n[i] + n[j] > target) --j;
        else if(n[i] + n[j] < target) ++i;
        else break;
    }
    vector<int> indices;
    for(int k = 0;k < len;++k)
    {
        if(numbers[k] == n[i] || numbers[k] == n[j]) indices.push_back(k + 1);
    }
    return indices;
}

vector<int> twoSum2(vector<int> &numbers, int target)
{
    unordered_map<int, int> nums;
    int len = numbers.size();
    vector<int> indices;
    for(int i = 0;i < len;++i)
    {
        int gap = target - numbers[i];
        if(nums.find(gap) != nums.end())
        {
            indices.push_back(nums[gap] + 1);
            indices.push_back(i + 1);
            break;
        }
        nums[numbers[i]] = i;
    }
    return indices;
}

int main()
{
    vector<int> n = {3,2,4};
    PrintVector(n);
    PrintVector(twoSum2(n, 6));
    return 0;
}

