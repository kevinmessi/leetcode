#include <iostream>
#include <vector>

using namespace std;

int candy1(vector<int> &ratings)
{
    int len = ratings.size();
    if (len == 0) return 0;
    vector<int> nums(len, 1);
    for (int i = 1; i < len; ++i)
    {
        if (ratings[i] > ratings[i - 1])
            nums[i] = nums[i - 1] + 1;
    }
    int candies = nums[len - 1];
    for (int i = len - 2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i + 1])
            nums[i] = max(nums[i], nums[i + 1] + 1);
        candies += nums[i];
    }
    return candies;
}

int candy(vector<int> &ratings)
{
    int len = ratings.size(), candies = 1, count = 0, peek = 1;
    for (int i = 1; i < len; ++i)
    {
        if (ratings[i] >= ratings[i - 1])
        {
            if (count > 0)
            {
                candies += count * (count + 1) / 2;
                if (count >= peek) candies += count - peek + 1;
                count = 0;
                peek = 1;
            }
            peek = ratings[i] == ratings[i - 1] ? 1 : (peek + 1);
            candies += peek;
        }
        else ++count;
    }
    if (count > 0)
    {
        candies += count * (count + 1) / 2;
        if (count >= peek) candies += count - peek + 1;
    }
    return candies;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
