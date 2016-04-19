#include <algorithm>
#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

vector<Interval> merge(vector<Interval> &intervals)
{
    int len = intervals.size();
    if (len == 0) return vector<Interval>();
    auto comp = [](const Interval &i1, const Interval &i2){ return i1.start < i2.start; };
    sort(intervals.begin(), intervals.end(), comp);
    vector<Interval> result{ intervals[0] };
    for (int i = 1; i < len; ++i)
    {
        Interval &temp = result.back();
        if (temp.end < intervals[i].start)
            result.push_back(intervals[i]);
        else
            temp.end = max(temp.end, intervals[i].end);
    }
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

