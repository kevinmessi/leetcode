#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        int len = nums.size();
        sum.push_back(0);
        for (int i = 0; i < len; ++i)
        {
            sum.push_back(sum.back() + nums[i]);
        }
    }

    int sumRange(int i, int j)
    {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

