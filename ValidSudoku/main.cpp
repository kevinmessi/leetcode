#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidFlag(vector<int>& flag)
{
    for(int i = 0;i < 9;++i)
    {
        if(flag[i] > 1) return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board)
{
    vector<int> flag(9, 0);
    for(int i = 0;i < 9;++i)
    {
        for(int j = 0;j < 9;++j)
        {
            if(board[i][j] != '.') ++flag[board[i][j] - '1'];
        }
        if(!isValidFlag(flag)) return false;
        fill(flag.begin(), flag.end(), 0);
    }
    for(int i = 0;i < 9;++i)
    {
        for(int j = 0;j < 9;++j)
        {
            if(board[j][i] != '.') ++flag[board[j][i] - '1'];
        }
        if(!isValidFlag(flag)) return false;
        fill(flag.begin(), flag.end(), 0);
    }
    for(int i = 0;i < 3;++i)
    {
        for(int j = 0;j < 3;++j)
        {
            for(int k = 0;k < 3;++k)
            {
                for(int l = 0;l < 3;++l)
                {
                    if(board[i*3 + k][j*3 + l] != '.') ++flag[board[i*3 + k][j*3 + l] - '1'];
                }
            }
            if(!isValidFlag(flag)) return false;
            fill(flag.begin(), flag.end(), 0);
        }
    }
    return true;
}

bool isValidSudoku2(vector<vector<char>>& board)
{
    vector<short> cols(9, 0);
    vector<short> blocks(9, 0);
    vector<short> rows(9, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int idx = 1 << (board[i][j] - '1');
                if (rows[i] & idx || cols[j] & idx || blocks[i/3 * 3 + j/3] & idx)
                    return false;
                rows[i] |= idx;
                cols[j] |= idx;
                blocks[i/3 * 3 + j/3] |= idx;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board;
    vector<char> line;
    line = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    board.push_back(line);
    line = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    board.push_back(line);
    line = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    board.push_back(line);
    line = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    board.push_back(line);
    line = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    board.push_back(line);
    line = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    board.push_back(line);
    line = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    board.push_back(line);
    line = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    board.push_back(line);
    line = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    board.push_back(line);
    cout << isValidSudoku2(board) << endl;
    return 0;
}

