#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void addOperators(const string &num, int target, size_t idx, long long cur,
                  long long delta, string s, vector<string> &result)
{
    if (idx == num.size())
    {
        if (target == cur) result.push_back(s);
        return;
    }
    long long oprd = 0;
    string oprd_str;
    for (size_t i = idx; i < num.size(); ++i)
    {
        oprd = 10 * oprd + num[i] - '0';
        oprd_str += num[i];
        addOperators(num, target, i + 1, cur + oprd, oprd, s + '+' + oprd_str, result);
        addOperators(num, target, i + 1, cur - oprd, -oprd, s + '-' + oprd_str, result);
        addOperators(num, target, i + 1, cur + delta * (oprd - 1), delta * oprd, s + '*' + oprd_str, result);
        if (num[idx] == '0') break;
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> result;
    long long oprd = 0;
    string oprd_str;
    for (size_t i = 0; i < num.size(); ++i)
    {
        oprd = 10 * oprd + num[i] - '0';
        oprd_str += num[i];
        addOperators(num, target, i + 1, oprd, oprd, oprd_str, result);
        if (num[0] == '0') break;
    }
    return result;
}

int main()
{
    //    "123", 6 -> ["1+2+3", "1*2*3"]
    //    "232", 8 -> ["2*3+2", "2+3*2"]
    //    "105", 5 -> ["1*0+5","10-5"]
    //    "00", 0 -> ["0+0", "0-0", "0*0"]
    //    "3456237490", 9191 -> []
    PrintVector(addOperators("123", 6));
    PrintVector(addOperators("232", 8));
    PrintVector(addOperators("105", 5));
    PrintVector(addOperators("00", 0));
    PrintVector(addOperators("3456237490", 9191));
    return 0;
}
