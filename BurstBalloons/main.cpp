#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= n - i; ++j)
        {
            int left_bound = j > 0 ? nums[j - 1] : 1;
            int right_bound = j + i < n ? nums[j + i] : 1;
            for (int k = j; k < j + i; ++k)
            {
                int coins = table[k - j][j] + table[j + i - k - 1][k + 1] + left_bound * nums[k] * right_bound;
                table[i][j] = max(table[i][j], coins);
            }
        }
    }
    return table[n][0];
}

int main()
{
    vector<int> nums { 3, 1, 5 };
    cout << maxCoins(nums) << endl;
    return 0;
}
