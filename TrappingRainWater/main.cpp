#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int trap1(vector<int> &height)
{
    int L = 0, R = height.size() - 1;
    int volume = 0, maxL = 0, maxR = 0;
    while (L <= R)
    {
        if (height[L] < height[R])
        {
            if (height[L] > maxL) maxL = height[L];
            else volume += maxL - height[L];
            ++L;
        }
        else
        {
            if (height[R] > maxR) maxR = height[R];
            else volume += maxR - height[R];
            --R;
        }
    }
    return volume;
}

int trap2(vector<int> &height)
{
    int L = 0, R = height.size() - 1;
    int volume = 0, maxL = 0, maxR = 0;
    while (L <= R)
    {
        maxL = max(maxL, height[L]);
        maxR = max(maxR, height[R]);
        if (maxL < maxR)
        {
            volume += maxL - height[L];
            ++L;
        }
        else
        {
            volume += maxR - height[R];
            --R;
        }
    }
    return volume;
}

int trap3(vector<int> &height)
{
    int L = 0, R = height.size() - 1;
    int volume = 0, level = 0;
    while (L < R)
    {
        int lower = height[height[L] < height[R] ? L++ : R--];
        level = max(level, lower);
        volume += level - lower;
    }
    return volume;
}

int trap4(vector<int> &height)
{
    if (height.empty()) return 0;
    int volume = 0, len = height.size(), i;
    vector<int> lmax(len, 0), rmax(len, 0);
    for (i = 1, lmax[0] = height[0]; i < len; ++i)
        lmax[i] = max(lmax[i - 1], height[i]);
    for (i = len - 2, rmax[len - 1] = height[len - 1]; i >= 0; --i)
        rmax[i] = max(rmax[i + 1], height[i]);
    for (i = 0; i < len; ++i)
        volume += min(lmax[i], rmax[i]) - height[i];
    return volume;
}

int trap(vector<int> &height)
{
    int volume = 0, len = height.size();
    stack<int> s;
    for (int i = 0; i < len;)
    {
        if (s.empty() || height[i] <= height[s.top()])
        {
            s.push(i++);
        }
        else
        {
            int bar = s.top();
            s.pop();
            if (!s.empty())
            {
                int j = s.top();
                volume += (min(height[j], height[i]) - height[bar]) * (i - j - 1);
            }
        }
    }
    return volume;
}

int main()
{
    vector<int> height{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << trap(height) << endl;
    return 0;
}

