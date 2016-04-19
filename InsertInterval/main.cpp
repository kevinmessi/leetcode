#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
    vector<Interval> result;
    int i = 0, len = intervals.size();
    for (; i < len && newInterval.end >= intervals[i].start; ++i)
    {
        if (newInterval.start > intervals[i].end) result.push_back(intervals[i]);
        else
        {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
    }
    result.push_back(newInterval);
    result.insert(result.end(), intervals.begin() + i, intervals.end());
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
