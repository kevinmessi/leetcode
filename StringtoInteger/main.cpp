#include <iostream>
#include <algorithm>

using namespace std;

int myAtoi(string str)
{
    int num = 0;
    int sign = 1;
    int len = str.length();
    int i = 0;
    for(;i < len && str[i] == ' ';++i);
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-') sign = -1;
        ++i;
    }
    if(str[i] < '0' || str[i] > '9') return 0;
    for(;i < len;++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            int digit = str[i] - '0';
            if(sign == 1 && ((num > 214748364) || (num == 214748364 && digit >= 8))) return INT_MAX;
            if(sign == -1 && ((num > 214748364) || (num == 214748364 && digit >= 9))) return INT_MIN;
            num = 10 * num + digit;
        }
        else break;
    }
    return num * sign;
}

int main()
{
    string s = "-2147483649";
    cout << myAtoi(s) << endl;
    cout << atoi(s.c_str()) << endl;
    return 0;
}

