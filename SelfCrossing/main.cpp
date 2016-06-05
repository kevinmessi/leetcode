#include <iostream>
#include <vector>

using namespace std;

bool isSelfCrossing1(vector<int> &x)
{
    int len = x.size();
    if (len > 4 && x[4] >= x[2] - x[0] && x[1] == x[3])
        return true;
    for (int i = 3; i < len; ++i)
    {
        if (x[i - 1] <= x[i - 3] && x[i] >= x[i - 2])
            return true;
        if (i >= 5 && x[i - 2] >= x [i - 4] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i - 1] <= x[i - 3] && x[i] >= x[i - 2] - x [i - 4])
            return true;
    }
    return false;
}

bool isSelfCrossing(vector<int> &x)
{
    int len = x.size(), i = 2;
    for (; i < len && x[i] > x[i - 2]; ++i)
        ;
    if (i >= len) return false;
    if (i > 2 && x[i] >= x[i - 2] - (i > 3 ? x[i - 4] : 0))
        x[i - 1] -= x[i - 3];
    for (++i; i < len && x[i] < x[i - 2]; ++i)
        ;
    return i < len;
}

int main()
{
    vector<int> nums{ 2, 2, 2 };
    cout << isSelfCrossing(nums) << endl;
    return 0;
}
