#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    if(n <= 0) return false;
    while(n > 1)
    {
        if(n % 2) return false;
        n /= 2;
    }
    return true;
}

bool isPowerOfTwo2(int n)
{
    return n > 0 && !(n&(n-1));
}

int main()
{
    cout << isPowerOfTwo2(12) << endl;
    return 0;
}

