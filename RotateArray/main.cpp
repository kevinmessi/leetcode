#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> v)
{
    int len = v.size();
    for(int i = 0;i < len;++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// O(n) space
void rotate(vector<int>& nums, int k)
{
    vector<int> tmp;
    int n = nums.size();
    k = k % n;
    for(int i = n - k, stop = i + n;i < stop;++i)
    {
        tmp.push_back(nums[i % n]);
    }
    nums = tmp;
}

// O(k) space
void rotate2(vector<int>& nums, int k)
{
    int n = nums.size();
    k = k % n;
    for(int i = n-1;i >= n-k;--i)
    {
        nums.push_back(nums[i]);
    }
    for(int i = n-1;i >= k;--i)
    {
        nums[i] = nums[i-k];
    }
    for(int i = 0;i < k;++i)
    {
        nums[i] = nums[n+k-1-i];
        nums.pop_back();
    }
}

void reverse(vector<int>& nums, int begin, int end)
{
    int middle = (begin + end) / 2;
    for(int i = begin;i <= middle;++i)
    {
        swap(nums[i], nums[end + begin - i]);
    }
}

//O(1) space
void rotate3(vector<int>& nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n-k-1);
    reverse(nums, n-k, n-1);
    reverse(nums, 0, n-1);
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8};
    PrintVector(v);
    rotate3(v,3);
    PrintVector(v);
    return 0;
}

