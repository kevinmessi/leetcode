#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum1(vector<int>& nums, int target)
{
    vector<vector<int>> slns;
    int len = nums.size();
    if (len < 4) return slns;
    sort(nums.begin(), nums.end());
    for (int i = len - 1; i >= 3; --i)
    {
        int target3 = target - nums[i];
        for (int j = i - 1; j >= 2; --j)
        {
            int target2 = target3 - nums[j];
            int left = 0, right = j - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > target2) --right;
                else if (sum < target2) ++left;
                else
                {
                    vector<int> quadruplet{ nums[left], nums[right], nums[j], nums[i] };
                    slns.push_back(quadruplet);
                    while (left < right && nums[left] == quadruplet[0]) ++left;
                    while (left < right && nums[right] == quadruplet[1]) --right;
                }
            }
            while (j >= 1 && nums[j - 1] == nums[j]) --j;
        }
        while (i >= 1 && nums[i - 1] == nums[i]) --i;
    }
    return slns;
}

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> slns;
    int len = nums.size();
    if (len < 4) return slns;
    sort(nums.begin(), nums.end());
    for (int i = len - 1; i >= 3; --i)
    {
        if (nums[i] + nums[i - 1] + nums[i - 2] + nums[i - 3] < target) break;
        if (nums[i] + nums[2] + nums[1] + nums[0] > target) continue;
        int target3 = target - nums[i];
        for (int j = i - 1; j >= 2; --j)
        {
            if (nums[j] + nums[j - 1] + nums[j - 2] < target3) break;
            if (nums[j] + nums[1] + nums[0] > target3) continue;
            int target2 = target3 - nums[j];
            int left = 0, right = j - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum > target2) --right;
                else if (sum < target2) ++left;
                else
                {
                    vector<int> quadruplet{ nums[left], nums[right], nums[j], nums[i] };
                    slns.push_back(quadruplet);
                    while (left < right && nums[left] == quadruplet[0]) ++left;
                    while (left < right && nums[right] == quadruplet[1]) --right;
                }
            }
            while (j >= 1 && nums[j - 1] == nums[j]) --j;
        }
        while (i >= 1 && nums[i - 1] == nums[i]) --i;
    }
    return slns;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

