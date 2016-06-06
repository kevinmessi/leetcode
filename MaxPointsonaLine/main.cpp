#include <iostream>
#include <unordered_map>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

int EuclideanGCD(int a, int b)
{
    while (b)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int maxPoints1(vector<Point> &points)
{
    unordered_map<int, unordered_map<int, int>> table;
    int len = points.size(), max_points = 0;
    for (int i = 0; i < len; ++i)
    {
        table.clear();
        int duplicate = 1, cur_max = 0;;
        for (int j = i + 1; j < len; ++j)
        {
            int delta_x = points[j].x - points[i].x;
            int delta_y = points[j].y - points[i].y;
            if (!delta_x && !delta_y)
            {
                ++duplicate;
                continue;
            }
            int gcd = EuclideanGCD(delta_x, delta_y);
            if (gcd)
            {
                delta_x /= gcd;
                delta_y /= gcd;
            }
            ++table[delta_x][delta_y];
            cur_max = max(cur_max, table[delta_x][delta_y]);
        }
        max_points = max(max_points, cur_max + duplicate);
    }
    return max_points;
}

struct pairhash
{
    size_t operator() (const pair<int, int>& p) const
    {
        size_t const h1(hash<int>()(p.first));
        size_t const h2(hash<int>()(p.second));
        return h1 ^ (h2 << 1);
    }
};

int maxPoints2(vector<Point> &points)
{
    unordered_map<pair<int, int>, int, pairhash> table;
    int len = points.size(), max_points = 0;
    for (int i = 0; i < len; ++i)
    {
        table.clear();
        int duplicate = 1, cur_max = 0;
        for (int j = i + 1; j < len; ++j)
        {
            int delta_x = points[j].x - points[i].x;
            int delta_y = points[j].y - points[i].y;
            if (!delta_x && !delta_y)
            {
                ++duplicate;
                continue;
            }
            int gcd = EuclideanGCD(delta_x, delta_y);
            if (gcd)
            {
                delta_x /= gcd;
                delta_y /= gcd;
            }
            ++table[make_pair(delta_x, delta_y)];
            cur_max = max(cur_max, table[make_pair(delta_x, delta_y)]);
        }
        max_points = max(max_points, cur_max + duplicate);
    }
    return max_points;
}

int maxPoints(vector<Point> &points)
{
    unordered_map<double, int> table;
    int len = points.size(), max_points = 0;
    for (int i = 0; i < len; ++i)
    {
        table.clear();
        int duplicate = 1, cur_max = 0, vertical = 0;
        for (int j = i + 1; j < len; ++j)
        {
            double delta_x = points[j].x - points[i].x;
            double delta_y = points[j].y - points[i].y;
            if (!delta_x)
            {
                if (!delta_y) ++duplicate;
                else ++vertical;
                continue;
            }
            double slope = delta_y / delta_x;
            ++table[slope];
            cur_max = max(cur_max, table[slope]);
        }
        max_points = max(max_points, max(cur_max, vertical) + duplicate);
    }
    return max_points;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
