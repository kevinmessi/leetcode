#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void PrintArray(vector<T> v)
{
    int l = v.size();
    for(int i = 0;i < l;i++)
    {
        cout << v[i] << "\n";
    }
    cout << endl;
}

template<typename T>
void PrintMatrix(vector<vector<T>> m)
{
    int r = m.size();
    for(int i = 0;i < r;i++)
    {
        PrintArray(m[i]);
    }
}

vector<string> transPos(vector<int>& state)
{
    vector<string> vs;
    int n = state.size();
    string s(n, '.');
    for(int i = 0;i < n;++i)
    {
        s[state[i]] = 'Q';
        vs.push_back(s);
        s[state[i]] = '.';
    }
    return vs;
}

bool isConflict(vector<int>& state, int pos)
{
    int len = state.size();
    for(int i = 0;i < len;++i)
    {
        if(state[i] == pos || abs(state[i] - pos) == len - i)
            return true;
    }
    return false;
}

void nQueens(int n, vector<int>& state, vector<vector<string>>& solutions)
{
    for(int i = 0;i < n;++i)
    {
        if(!isConflict(state, i))
        {
            state.push_back(i);
            if(n == (int)state.size())
                solutions.push_back(transPos(state));
            else
                nQueens(n, state, solutions);
            state.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<int> state;
    nQueens(n, state, solutions);
    return solutions;
}

int main()
{
    vector<vector<string>> solutions = solveNQueens(8);
    PrintMatrix(solutions);
    cout << solutions.size() << endl;
    return 0;
}

