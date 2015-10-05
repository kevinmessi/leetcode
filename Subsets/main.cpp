#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > subsets(vector<int> &S)
{
    vector<vector<int> > sets;
    sets.push_back(vector<int>(0));
    sort(S.begin(), S.end());
    int len = S.size();
    for(int i = 0;i < len;++i)
    {
        int l = sets.size();
        for(int j = 0;j < l;++j)
        {
            vector<int> subset = sets[j];
            subset.push_back(S[i]);
            sets.push_back(subset);
        }
    }
    return sets;
}
int main()
{
    vector<int> s = {1,2,8,4,0};
    vector<vector<int> > sets = subsets(s);
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

