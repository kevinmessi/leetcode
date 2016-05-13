#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int m = dungeon.size(), n = dungeon[0].size();
    vector<int> hp(n + 1, INT_MAX);
    hp[n - 1] = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
            hp[j] = max(min(hp[j + 1], hp[j]) - dungeon[i][j], 1);
    }
    return hp[0];
}

int main()
{
    vector<vector<int>> dungeon
    {
        { -2, -3, 3 },
        { -5, -10, 1 },
        { 10, 30, -5 }
    };
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}
