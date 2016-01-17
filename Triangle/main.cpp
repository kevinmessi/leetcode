#include <iostream>
#include <vector>

using namespace std;

int minimumTotal1(vector<vector<int>>& triangle)
{
    int n = triangle.size();
    if (n == 0) return 0;
    vector<int> v(n);
    v[0] = triangle[0][0];
    for (int i = 1; i < n; ++i)
    {
        int left, right = v[0];
        v[0] = triangle[i][0] + v[0];
        for (int j = 1; j < i; ++j)
        {
            left = right, right = v[j];
            v[j] = min(left, right) + triangle[i][j];
        }
        v[i] = triangle[i][i] + right;
    }
    int minimum = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        minimum = min(minimum, v[i]);
    }
    return minimum;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    if (n == 0) return 0;
    vector<int> v(triangle.back());
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            v[j] = min(v[j], v[j + 1]) + triangle[i][j];
        }
    }
    return v[0];
}

int main()
{
    vector<vector<int>> triangle;
    triangle.push_back({2});
    triangle.push_back({6, 4});
    triangle.push_back({6, 5, 7});
    triangle.push_back({4, 1, 8, 3});
    cout << minimumTotal(triangle) << endl;
    return 0;
}

