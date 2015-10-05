#include <iostream>
#include <vector>
#include <set>

using namespace std;

void PrintMatrix(vector<vector<int> > &matrix)
{
    int m = matrix.size();
    for(int i = 0;i < m;++i)
    {
        int n = matrix[i].size();
        for(int j = 0;j < n;++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------" <<endl;
}

void setZeroes3(vector<vector<int> > &matrix)
{
    int m = matrix.size();
    if(m == 0) return;
    int n = matrix[0].size();
    vector<vector<int> > tmp = matrix;
    for(int i = 0;i < m;++i)
    {
        for(int j = 0;j < n;++j)
        {
            if(tmp[i][j] == 0)
            {
                for(int k = 0;k < n;++k)
                {
                    matrix[i][k] = 0;
                }
                for(int k = 0;k < m;++k)
                {
                    matrix[k][j] = 0;
                }
            }
        }
    }
}

void setZeroes2(vector<vector<int> > &matrix)
{
    int m = matrix.size();
    if(m == 0) return;
    int n = matrix[0].size();
    vector<int> rows;
    vector<int> cols;
    for(int i = 0;i < m;++i)
    {
        for(int j = 0;j < n;++j)
        {
            if(matrix[i][j] == 0)
            {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }
    int r = rows.size();
    int c = cols.size();
    for(int i = 0;i < r;++i)
    {
        for(int j = 0;j < n;++j)
        {
            matrix[rows[i]][j] = 0;
        }
    }
    for(int j = 0;j < c;++j)
    {
        for(int i = 0;i < m;++i)
        {
            matrix[i][cols[j]] = 0;
        }
    }
}

void setZeroes(vector<vector<int> > &matrix)
{
    int m = matrix.size();
    if(m == 0) return;
    int n = matrix[0].size();
    if(n == 0) return;
    bool row0 = false, col0 = false;
    for(int i = 0;i < m;++i)
    {
        if(matrix[i][0] == 0)
        {
            col0 = true;
            break;
        }
    }
    for(int j = 0;j < n;++j)
    {
        if(matrix[0][j] == 0)
        {
            row0 = true;
            break;
        }
    }
    for(int i = 1;i < m;++i)
    {
        for(int j = 1;j < n;++j)
        {
            if(matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1;i < m;++i)
    {
        if(matrix[i][0] == 0)
        {
            for(int k = 0;k < n;++k)
            {
                matrix[i][k] = 0;
            }
        }
    }
    for(int j = 1;j < n;++j)
    {
        if(matrix[0][j] == 0)
        {
            for(int k = 0;k < m;++k)
            {
                matrix[k][j] = 0;
            }
        }
    }
    if(row0)
    {
        for(int k = 0;k < n;++k)
        {
            matrix[0][k] = 0;
        }
    }
    if(col0)
    {
        for(int k = 0;k < m;++k)
        {
            matrix[k][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int> > matrix;
    matrix.push_back({1,2,1,7});
    matrix.push_back({0,1,5,0});
    matrix.push_back({4,3,2,1});
    matrix.push_back({0,5,3,1});
    PrintMatrix(matrix);
    setZeroes3(matrix);
    PrintMatrix(matrix);
    return 0;
}

