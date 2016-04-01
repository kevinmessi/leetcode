#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea1(vector<int> &heights, int begin, int end)
{
    if (begin > end) return 0;
    int area = 0, mid = begin + (end - begin) / 2;
    int i = mid, j = mid, h = heights[mid];
    while (i >= begin && j <= end)
    {
        h = min(h, min(heights[i], heights[j]));
        area = max(area, (j - i + 1) * h);
        if (i == begin) ++j;
        else if (j == end) --i;
        else
        {
            if (heights[i - 1] > heights[j + 1]) --i;
            else ++j;
        }
    }
    area = max(area, largestRectangleArea1(heights, begin, mid - 1));
    area = max(area, largestRectangleArea1(heights, mid + 1, end));
    return area;
}

int largestRectangleArea1(vector<int> &heights)
{
    return largestRectangleArea1(heights, 0, heights.size() - 1);
}

int largestRectangleArea2(vector<int> &heights)
{
    stack<int> s;
    int area = 0, len = heights.size(), i = 0;
    while (i < len)
    {
        if (s.empty() || heights[i] >= heights[s.top()])
        {
            s.push(i++);
        }
        else
        {
            int bar = s.top();
            s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            area = max(area, heights[bar] * width);
        }
    }
    while (!s.empty())
    {
        int bar = s.top();
        s.pop();
        int width = s.empty() ? i : (i - s.top() - 1);
        area = max(area, heights[bar] * width);
    }
    return area;
}

int largestRectangleArea(vector<int> &heights)
{
    int area = 0, len = heights.size(), cur = 1;
    vector<int> s(len + 2, 0);
    s[0] = -1;
    for (int i = 1; i <= len; ++i)
    {
        int h = i == len ? 0 : heights[i];
        while (cur && h < heights[s[cur]])
        {
            area = max(area, heights[s[cur]] * (i - s[cur - 1] - 1));
            --cur;
        }
        s[++cur] = i;
    }
    return area;
}

int main()
{
    vector<int> heights{ 2, 1, 5, 6, 2, 3 };
    cout << largestRectangleArea(heights) << endl;
    return 0;
}

