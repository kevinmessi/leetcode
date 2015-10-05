#include <iostream>

using namespace std;

int divide(int dividend, int divisor)
{
    bool positive = true;
    if(divisor == 0) return INT_MAX;
    if(divisor == 1) return dividend;
    if(dividend == divisor) return 1;
    if(divisor == INT_MIN) return 0;
    if(dividend == INT_MIN)
    {
        if(divisor == -1) return INT_MAX;
        if(divisor == -2) return 0x40000000;
        if(divisor == 2) return -0x40000000;
        dividend = INT_MAX;
        positive = !positive;
    }
    else if(dividend < 0)
    {
        dividend = -dividend;
        positive = !positive;
    }
    if(divisor < 0)
    {
        divisor = -divisor;
        positive = !positive;
    }
    int quotient = 0, tmp_div = divisor, fact;
    while(dividend >= divisor)
    {
        fact = 1;
        while(dividend >> 1 >= tmp_div)
        {
            tmp_div = tmp_div << 1;
            fact = fact << 1;
        }
        dividend -= tmp_div;
        quotient += fact;
        tmp_div = divisor;
    }
    return positive ? quotient : -quotient;
}

int main()
{
    int a = 2147483647, b = 2;
    cout << divide(a,b) << endl;
    cout << a/b << endl;
    return 0;
}

