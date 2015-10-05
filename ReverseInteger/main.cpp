#include <iostream>

using namespace std;

int reverse(int x)
{
    bool positive = true;
    if(x < 0)
    {
        x = -x;
        positive = false;
    }
    int rx = 0;
    while(x >= 1)
    {
        if(rx > 214748364 ) return 0;
        rx = x % 10 + rx * 10;
        x = x / 10;
    }
    return positive? rx:(-rx);
}

int main()
{
    //cout << reverse(2147483647) << endl;
    //cout << (int)-2147483648 <<endl;
    cout << reverse(1534236469) << endl;
    return 0;
}

