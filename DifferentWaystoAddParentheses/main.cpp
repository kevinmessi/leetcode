#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

vector<int> diffWaysToCompute1(string input)
{
    vector<int> results;
    int len = input.size();
    for (int i = 0; i < len; ++i)
    {
        if (isdigit(input[i])) continue;
        for (int l : diffWaysToCompute1(input.substr(0, i)))
        {
            for (int r : diffWaysToCompute1(input.substr(i + 1, len - i - 1)))
            {
                switch (input[i])
                {
                case '+':
                    results.push_back(l + r);
                    break;
                case '-':
                    results.push_back(l - r);
                    break;
                case '*':
                    results.push_back(l * r);
                    break;
                default:
                    break;
                }
            }
        }
    }
    if (results.empty()) results.push_back(stoi(input));
    return results;
}

vector<int> diffWaysToCompute(vector<int> &operands, vector<char> &operators)
{
    int len = operands.size();
    vector<vector<vector<int>>> results(len);
    for (int num : operands)
        results[0].push_back({ num });
    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j < len - i; ++j)
        {
            results[i].push_back({});
            for (int k = j; k < j + i; ++k)
            {
                for (int left : results[k - j][j])
                {
                    for (int right : results[j + i - k - 1][k + 1])
                    {
                        switch (operators[k])
                        {
                        case '+':
                            results[i][j].push_back(left + right);
                            break;
                        case '-':
                            results[i][j].push_back(left - right);
                            break;
                        case '*':
                            results[i][j].push_back(left * right);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
    }
    return results[len - 1][0];
}

vector<int> diffWaysToCompute(string input)
{
    vector<int> operands;
    vector<char> operators;
    int len = input.size(), num = 0;
    for (int i = 0; i < len; ++i)
    {
        if (isdigit(input[i]))
            num = num * 10 + input[i] - '0';
        else
        {
            operands.push_back(num);
            operators.push_back(input[i]);
            num = 0;
        }
    }
    operands.push_back(num);
    return diffWaysToCompute(operands, operators);
}

int main()
{
    PrintVector(diffWaysToCompute("2*3-4*5"));
    return 0;
}

