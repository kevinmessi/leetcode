#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

vector<string> generateParenthesis1(int n)
{
    vector<vector<string>> T{ vector<string>{ "" } };
    for (int i = 1; i <= n; ++i)
    {
        vector<string> parentheses;
        for (int j = 0; j < i; ++j)
        {
            for (auto &left : T[j])
            {
                for (auto &right : T[i - j - 1])
                {
                    parentheses.push_back("(" + left + ")" + right);
                }
            }
        }
        T.push_back(parentheses);
    }
    return T[n];
}

void AddParenthesis(const string &parenthesis, int left, int right, vector<string> &parentheses)
{
    if (left == 0 && right == 0)
    {
        parentheses.push_back(parenthesis);
        return;
    }
    if (left > 0)
        AddParenthesis(parenthesis + "(", left - 1, right, parentheses);
    if (right > left)
        AddParenthesis(parenthesis + ")", left, right - 1, parentheses);
}

vector<string> generateParenthesis(int n)
{
    vector<string> parentheses;
    AddParenthesis("", n, n, parentheses);
    return parentheses;
}

int main()
{
    PrintVector(generateParenthesis(3));
    return 0;
}

