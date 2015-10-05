#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows)
{
    vector<vector<int> > v;
    if(numRows <= 0) return v;
    v.push_back({1});
    for(int i=1;i<numRows;++i)
    {
        vector<int> row;
        row.push_back(1);
        for(int j=1;j<i;++j)
        {
            row.push_back(v[i-1][j] + v[i-1][j-1]);
        }
        row.push_back(1);
        v.push_back(row);
    }
    return v;
}

int main()
{
    generate(3);
    cout << "Hello World!" << endl;
    return 0;
}

