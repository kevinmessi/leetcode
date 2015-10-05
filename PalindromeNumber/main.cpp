#include <time.h>
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x)
{
    if(x < 0) return false;
    int tmp = x;
    long long rx = 0;
    while(tmp >= 1)
    {
        rx = tmp % 10 + rx * 10;
        tmp = tmp / 10;
    }
    return rx == (long long)x;
}

int main()
{
    cout << isPalindrome(145979541) << endl;
    return 0;
}

