#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S)
{
    vector<vector<int> > sets;
    sets.push_back(vector<int>(0));
    sort(S.begin(), S.end());
    int len = S.size();
    int index = 0;
    for(int i = 0;i < len;++i)
    {
        int l = sets.size();
        int j = 0;
        if(i != 0 && S[i] == S[i-1]) j = index;
        for(;j < l;++j)
        {
            vector<int> subset = sets[j];
            subset.push_back(S[i]);
            sets.push_back(subset);
        }
        index = l;
    }
    return sets;
}
int main()
{
    vector<int> s = {1,2,2,2,3};
    vector<vector<int> > sets = subsetsWithDup(s);
    for(size_t i = 0;i < sets.size();++i)
    {
        for(size_t j = 0;j < sets[i].size();++j)
        {
            cout << sets[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Size: " << sets.size() << endl;
    return 0;
}

