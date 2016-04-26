#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

bool solveSudoku1(vector<vector<char>> &board, int begin, short *rows, short *cols, short *subs)
{
    for (int s = begin; s < 81; ++s)
    {
        int i = s / 9, j = s % 9, k = (i / 3) * 3 + j / 3;;
        if (board[i][j] == '.')
        {
            for (int n = 0; n < 9; ++n)
            {
                short flag = 1 << n;
                if (!(rows[i] & flag) && !(cols[j] & flag) && !(subs[k] & flag))
                {
                    board[i][j] = n + '1';
                    rows[i] |= flag; cols[j] |= flag; subs[k] |= flag;
                    if (solveSudoku1(board, s + 1, rows, cols, subs)) return true;
                    board[i][j] = '.';
                    rows[i] &= ~flag; cols[j] &= ~flag; subs[k] &= ~flag;
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku1(vector<vector<char>> &board)
{
    short rows[9]{ 0 }, cols[9]{ 0 }, subs[9]{ 0 };
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                short flag = 1 << (board[i][j] - '1');
                int k = (i / 3) * 3 + j / 3;
                rows[i] |= flag; cols[j] |= flag; subs[k] |= flag;
            }
        }
    }
    solveSudoku1(board, 0, rows, cols, subs);
}

bool solveSudoku(int *sequence, int begin, short *rows, short *cols, short *subs,
                 const int *row_index, const int *col_index, const int *sub_index)
{
    for (int s = begin; s < 81; ++s)
    {
        int i = row_index[s], j = col_index[s], k = sub_index[s];
        if (!sequence[s])
        {
            short candidates = ~rows[i] & ~cols[j] & ~subs[k];
            while (candidates & 0x1ff)
            {
                short val = candidates & (-candidates);
                sequence[s] = val;
                rows[i] |= val; cols[j] |= val; subs[k] |= val;
                if (solveSudoku(sequence, s + 1, rows, cols, subs, row_index, col_index, sub_index))
                    return true;
                sequence[s] = 0;
                rows[i] &= ~val; cols[j] &= ~val; subs[k] &= ~val;
                candidates &= ~val;
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    short rows[9]{ 0 }, cols[9]{ 0 }, subs[9]{ 0 };
    int sequence[81]{ 0 }, row_index[81], col_index[81], sub_index[81];
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int s = 9 * i + j;
            row_index[s] = i; col_index[s] = j; sub_index[s] = (i / 3) * 3 + j / 3;
            if (board[i][j] != '.')
            {
                sequence[s] = 1 << (board[i][j] - '1');
                rows[i] |= sequence[s]; cols[j] |= sequence[s]; subs[sub_index[s]] |= sequence[s];
            }
        }
    }
    solveSudoku(sequence, 0, rows, cols, subs, row_index, col_index, sub_index);
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.')
            {
                int s = 9 * i + j, n;
                for (n = 0; sequence[s] != (1 << n); ++n)
                    ;
                board[i][j] = n + '1';
            }
        }
    }
}

int main()
{
    vector<vector<char>> board
    {
        { '.', '.', '9', '7', '4', '8', '.', '.', '.' },
        { '7', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '2', '.', '1', '.', '9', '.', '.', '.' },
        { '.', '.', '7', '.', '.', '.', '2', '4', '.' },
        { '.', '6', '4', '.', '1', '.', '5', '9', '.' },
        { '.', '9', '8', '.', '.', '.', '3', '.', '.' },
        { '.', '.', '.', '8', '.', '3', '.', '2', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '6' },
        { '.', '.', '.', '2', '7', '5', '9', '.', '.' }
    };
    PrintMatrix(board);
    cout << endl;
    solveSudoku(board);
    PrintMatrix(board);
    return 0;
}
