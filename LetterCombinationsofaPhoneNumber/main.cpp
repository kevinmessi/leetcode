#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void letterCombinations(const vector<string> &map, const string &digits, int n, const string &letters,
                        vector<string> &combinations)
{
    if (n == (int)digits.length())
    {
        combinations.push_back(letters);
        return;
    }
    for (const auto &letter : map[digits[n] - '2'])
    {
        letterCombinations(map, digits, n + 1, letters + letter, combinations);
    }
}

vector<string> letterCombinations1(string digits)
{
    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> combinations;
    if (digits.length() != 0)
        letterCombinations(map, digits, 0, "", combinations);
    return combinations;
}

vector<string> letterCombinations(string digits)
{
    vector<string> combinations;
    if (digits.length() == 0)
        return combinations;
    combinations.push_back("");
    vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (auto &digit : digits)
    {
        vector<string> temp(move(combinations));
        for (auto &letter : map[digit - '2'])
        {
            for (auto &combination : temp)
            {
                combinations.push_back(combination + letter);
            }
        }
    }
    return combinations;
}

int main()
{
    PrintVector(letterCombinations("425"));
    return 0;
}

