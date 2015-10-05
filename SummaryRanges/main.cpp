//Given a sorted integer array without duplicates, return the summary of its ranges.
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;

template <typename T>
void PrintArray(const vector<T>& v, const string& seperator)
{
    int len = v.size();
    for(int i = 0;i < len;i++)
    {
        cout << v[i] << seperator;
    }
    cout << endl;
}

string to_string(const pair<int, int>& p)
{
    string s;
    ostringstream oss;
    oss<<p.first;
    s.append(oss.str());
    if(p.first != p.second)
    {
        oss.str("");
        oss<<p.second;
        s.append("->" + oss.str());
    }
    return s;
}

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> ranges;
    int len = nums.size();
    if(len == 0) return ranges;
    pair<int, int> range(nums[0], nums[0]);
    for(int i = 1;i < len;++i)
    {
        if(nums[i-1] + 1 == nums[i])
        {
            ++range.second;
        }
        else
        {
            ranges.push_back(to_string(range));
            range = make_pair(nums[i], nums[i]);
        }
    }
    ranges.push_back(to_string(range));
    return ranges;
}

int main()
{
    vector<int> nums = {0,1,2,4,5,7};
    PrintArray(summaryRanges(nums), " ");
    return 0;
}

