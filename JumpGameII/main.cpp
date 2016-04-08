#include <iostream>
#include <vector>

using namespace std;

int jump1(vector<int> &nums)
{
    int n = nums.size(), step = 0, utmost = 0, i = 0;
    while (i <= utmost)
    {
        int temp = utmost;
        for (; i <= temp; ++i)
        {
            if (i == n - 1) return step;
            utmost = max(utmost, i + nums[i]);
        }
        ++step;
    }
    return -1;
}

int jump(vector<int> &nums)
{
    int n = nums.size(), step = 0, utmost = 0, edge = 0;
    for (int i = 0; i <= edge; ++i)
    {
        if (i == n - 1) return step;
        utmost = max(utmost, i + nums[i]);
        if (i == edge)
        {
            edge = utmost;
            ++step;
        }
    }
    return -1;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
