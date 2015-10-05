#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void PrintVector(vector<int> v)
{
    for(unsigned int i = 0;i < v.size();++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<vector<int> > twoSum(const vector<int> &num, int target)
{
    int len = num.size();
    int i = 0,j = len - 1;
    vector<vector<int> > pairs;
    while(i < j)
    {
        if(num[i] + num[j] > target) --j;
        else if(num[i] + num[j] < target) ++i;
        else
        {
            int l = pairs.size();
            if(l == 0 || pairs[l-1][0] != num[i] || pairs[l-1][1] != num[j])
                pairs.push_back({num[i],num[j]});
            ++i;
            --j;
        }
    }
    return pairs;
}

vector<vector<int> > threeSum(vector<int> &num)
{
    sort(num.begin(),num.end());
    vector<vector<int> > triplets;
    int len  = num.size();
    int last;
    for(int i = len - 1;i >= 0;--i)
    {
        if(i != len - 1 && num[i] == last)
        {
            num.pop_back();
            continue;
        }
        last = num[i];
        num.pop_back();
        int ln = num.size();
        int ii = 0,jj = ln - 1;
        while(ii < jj)
        {
            if(num[ii] + num[jj] + last > 0) --jj;
            else if(num[ii] + num[jj] + last < 0) ++ii;
            else
            {
                int l = triplets.size();
                if(l == 0 || triplets[l-1][0] != num[ii] || triplets[l-1][1] != num[jj])
                {
                    triplets.push_back({num[ii], num[jj], last});
                }
                ++ii;
                --jj;
            }
        }
    }
    return triplets;
}

int main()
{
    vector<int> n = {1, -1, 1, -1 ,1, 1, 0};
//    vector<int> n = {0};
//    sort(n.begin(),n.end());
//    PrintVector(n);
    vector<vector<int> > pairs = threeSum(n);
//    vector<vector<int> > pairs = twoSum(n, 1);
//    cout << "--------------------" << endl;
    int len = pairs.size();
    for(int i = 0;i < len;++i)
    {
        PrintVector(pairs[i]);
    }
    return 0;
}

