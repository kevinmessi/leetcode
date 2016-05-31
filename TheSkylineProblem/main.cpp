#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> getSkyline1(vector<vector<int>> &buildings)
{
    vector<pair<int, int>> skyline;
    int len = buildings.size(), idx = 0, height, position;
    priority_queue<pair<int, int>> live_buildings;
    while (idx < len || !live_buildings.empty())
    {
        if (live_buildings.empty() || (idx < len && buildings[idx][0] <= live_buildings.top().second))
        {
            position = buildings[idx][0];
            while (idx < len && buildings[idx][0] == position)
            {
                live_buildings.emplace(buildings[idx][2], buildings[idx][1]);
                ++idx;
            }
        }
        else
        {
            position = live_buildings.top().second;
            while (!live_buildings.empty() && position >= live_buildings.top().second)
                live_buildings.pop();
        }
        height = live_buildings.empty() ? 0 : live_buildings.top().first;
        if (skyline.empty() || skyline.back().second != height)
            skyline.emplace_back(position, height);
    }
    return skyline;
}

void AddPoint(vector<pair<int, int>> &skyline, int x, int h)
{
    if (skyline.empty() || skyline.back().second != h)
        skyline.emplace_back(x, h);
}

void getSkyline(vector<vector<int>> &buildings, int begin, int end, vector<pair<int, int>> &skyline)
{
    if (begin == end)
    {
        skyline.emplace_back(buildings[begin][0], buildings[begin][2]);
        skyline.emplace_back(buildings[begin][1], 0);
        return;
    }
    vector<pair<int, int>> left, right;
    int middle = begin + (end - begin) / 2;
    getSkyline(buildings, begin, middle, left);
    getSkyline(buildings, middle + 1, end, right);
    int i = 0, j = 0, m = left.size(), n = right.size(), h1 = 0, h2 = 0;
    while (i < m && j < n)
    {
        if (left[i].first < right[j].first)
        {
            AddPoint(skyline, left[i].first, max(h2, left[i].second));
            h1 = left[i++].second;
        }
        else if (left[i].first > right[j].first)
        {
            AddPoint(skyline, right[j].first, max(h1, right[j].second));
            h2 = right[j++].second;
        }
        else
        {
            AddPoint(skyline, left[i].first, max(left[i].second, right[j].second));
            h1 = left[i++].second;
            h2 = right[j++].second;
        }
    }
    for (; i < m; ++i)
        AddPoint(skyline, left[i].first, left[i].second);
    for (; j < n; ++j)
        AddPoint(skyline, right[j].first, right[j].second);
}

vector<pair<int, int>> getSkyline2(vector<vector<int>> &buildings)
{
    vector<pair<int, int>> skyline;
    if (!buildings.empty())
        getSkyline(buildings, 0, buildings.size() - 1, skyline);
    return skyline;
}

vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<pair<int, int>> skyline;
    multimap<int, int> points;
    for (const auto &rect : buildings)
    {
        points.emplace(rect[0], rect[2]);
        points.emplace(rect[1], -rect[2]);
    }
    multiset<int> heights{ 0 };
    int x = -1, h = 0;
    for (const auto &p : points)
    {
        if (x >= 0 && p.first != x && (skyline.empty() || skyline.back().second != h))
            skyline.emplace_back(x, h);
        if (p.second >= 0)
            heights.insert(p.second);
        else
            heights.erase(heights.find(-p.second));
        x = p.first;
        h = *heights.rbegin();
    }
    if (!skyline.empty() && skyline.back().second != h)
        skyline.emplace_back(x, h);
    return skyline;
}

int main()
{
    vector<vector<int>> buildings
    {
        { 2, 9, 10 },
        { 3, 7, 15 },
        { 5, 12, 12 },
        { 15, 20, 10 },
        { 19, 24, 8 }
    };
    auto skyline = getSkyline(buildings);
    //[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]
    cout << skyline.size() << endl;
    return 0;
}
