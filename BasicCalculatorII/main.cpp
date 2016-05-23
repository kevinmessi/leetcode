#include <iostream>

using namespace std;

int calculate(string s)
{
    int result = 0, num = 0, pre = 1;
    bool multipy = true;
    for (char c : s)
    {
        if (isdigit(c)) num = 10 * num + c - '0';
        else
        {
            if (isspace(c)) continue;
            pre = multipy ? pre * num : pre / num;
            if (c == '+')
            {
                result += pre;
                pre = 1;
            }
            else if (c == '-')
            {
                result += pre;
                pre = -1;
            }
            multipy = !(c == '/');
            num = 0;
        }
    }
    return result + (multipy ? pre * num : pre / num);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
