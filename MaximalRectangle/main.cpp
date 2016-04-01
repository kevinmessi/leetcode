#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maximalRectangle1(vector<vector<char>> &matrix)
{
    int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
    int area = 0;
    vector<int> h(n + 1);
    h[n] = 0;
    for (int i = 0; i < m; ++i)
    {
        stack<int> s;
        for (int j = 0; j <= n; ++j)
        {
            if (j < n)
            {
                if (matrix[i][j] == '1') h[j] += 1;
                else h[j] = 0;
            }
            while (!s.empty() && h[j] < h[s.top()])
            {
                int low = s.top();
                s.pop();
                area = max(area, h[low] * (s.empty() ? j : (j - s.top() - 1)));
            }
            s.push(j);
        }
    }
    return area;
}

int maximalRectangle2(vector<vector<char>> &matrix)
{
    int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
    int area = 0;
    vector<int> heights(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int cur = 0;
        vector<int> s(n + 2, 0);
        s[0] = -1;
        for (int j = 0; j <= n; ++j)
        {
            if (j < n)
            {
                if (matrix[i][j] == '1') ++heights[j];
                else heights[j] = 0;
            }
            int h = j == n ? 0 : heights[j];
            while (cur && h < heights[s[cur]])
            {
                area = max(area, heights[s[cur]] * (j - s[cur - 1] - 1));
                --cur;
            }
            s[++cur] = j;
        }
    }
    return area;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
    int area = 0;
    vector<int> left(n, 0), right(n, n), height(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int cur_left = 0, cur_right = n;
        for (int j = n - 1; j >= 0; j--)
        {
            if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
            else { right[j] = n; cur_right = j; }
        }
        for (int j = 0; j < n; ++j)
        {

            if (matrix[i][j] == '1')
            {
                height[j]++;
                left[j] = max(left[j], cur_left);
            }
            else
            {
                height[j] = 0;
                left[j] = 0; cur_left = j + 1;
            }
            area = max(area, (right[j] - left[j]) * height[j]);
        }
    }
    return area;
}

int main()
{
    vector<vector<char>> matrix
    {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' }
    };
    cout << maximalRectangle(matrix) << endl;
    return 0;
}

