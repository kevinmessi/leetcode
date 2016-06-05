#include <iostream>
#include <unordered_map>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
int maxPoints(vector<Point> &points)
{
    int max_points = 0, len = points.size();
    unordered_map<double, Point> table;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {

        }
    }
    return max_points;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
