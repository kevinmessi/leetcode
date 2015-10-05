#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> v)
{
    int len = v.size();
    for(int i = 0;i < len;++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1, 0);
    row[0] = 1;
    for(int i = 1;i <= rowIndex;++i)
    {
        for(int j = i;j >= 1;--j)
        {
            row[j] += row[j-1];
        }
    }
    return row;
}

vector<int> getRow2(int rowIndex)
{
    vector<int> row(rowIndex + 1);
    row[0] = 1;
    long long n;
    for(int i = 1;i <= rowIndex;++i)
    {
        n = row[i-1];
        n *= (rowIndex - i + 1);
        n /= i;
        row[i] = n;
    }
    return row;
}

int main()
{
    PrintVector(getRow(30));
    return 0;
}

