#include <iostream>
#include <vector>

using namespace std;

bool is_conflict(vector<int> &state, int pos)
{
    int len = state.size();
    for (int i = 0; i < len; ++i)
    {
        if (pos == state[i] || abs(pos - state[i]) == len - i)
            return true;
    }
    return false;
}

void nQueens1(int n, vector<int> &state, int &count)
{
    if (n == (int)state.size())
    {
        ++count;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!is_conflict(state, i))
        {
            state.push_back(i);
            nQueens1(n, state, count);
            state.pop_back();
        }
    }
}

int totalNQueens1(int n)
{
    vector<int> state;
    int count = 0;
    nQueens1(n, state, count);
    return count;
}

void nQueens(int n, int r, vector<int> &col, vector<int> &diag1, vector<int> &diag2, int &count)
{
    if (n == r)
    {
        ++count;
        return;
    }
    for (int c = 0; c < n; ++c)
    {
        int d1 = r + c, d2 = n + r - c - 1;
        if (!col[c] && !diag1[d1] && !diag2[d2])
        {
            col[c] = diag1[d1] = diag2[d2] = 1;
            nQueens(n, r + 1, col, diag1, diag2, count);
            col[c] = diag1[d1] = diag2[d2] = 0;
        }
    }
}

int totalNQueens(int n)
{
    vector<int> col(n, 0);
    vector<int> diag1(2 * n - 1, 0);
    vector<int> diag2(2 * n - 1, 0);
    int count = 0;
    nQueens(n, 0, col, diag1, diag2, count);
    return count;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

