#include <iostream>

using namespace std;

long long int Factorial(int n)
{
    long long f = 1;
    for(int i = 1;i <= n;++i)
    {
        f *= i;
    }
    return f;
}

int trailingZeroes(int n)
{
    if(n == 0) return 0;
    int zeros = 0;
    int j = 1;
    for(int i = n;i >= 5;i /= 5, j *= 5)
    {
        zeros = zeros * 5 + 1;
    }
    zeros += trailingZeroes(n - j);
    return zeros;
}

int trailingZeroes2(int n)
{
    int zeros = 0;
    while(n >= 5)
    {
        n /= 5;
        zeros += n;
    }
    return zeros;
}

int main()
{
    int n = 137;
//    cout << Factorial(n) << endl;
    cout << trailingZeroes2(n) << endl;
    return 0;
}

