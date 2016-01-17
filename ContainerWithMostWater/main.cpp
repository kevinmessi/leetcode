#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height)
{
    int n = height.size();
    int max_area = 0, L = 0, R = n - 1, H = 0;
    while(L < R)
    {
        while (L < n && height[L] <= H)
            ++L;
        while (R >= 0 && height[R] <= H)
            --R;
        H = min(height[L], height[R]);
        max_area = max(max_area, (R - L) * H);
    }
    return max_area;
}

int main()
{
    vector<int> v = {2,2,2,2,2};
    cout << maxArea(v) << endl;
    return 0;
}

