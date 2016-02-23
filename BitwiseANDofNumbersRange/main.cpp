#include <iostream>

using namespace std;

int rangeBitwiseAnd1(int m, int n)
{
    int i = 0;
    while (m != n)
    {
        m >>= 1;
        n >>= 1;
        ++i;
    }
    return n << i;
}

int rangeBitwiseAnd2(int m, int n)
{
    return (n > m) ? (rangeBitwiseAnd2(m / 2, n / 2) << 1) : m;
}

int rangeBitwiseAnd3(int m, int n)
{
    int r = INT_MAX;
    while ((m & r) != (n & r))
        r = r << 1;
    return n & r;
}

int rangeBitwiseAnd4(int m, int n)
{
    while (m < n)
        n &= n - 1;
    return n;
}

int rangeBitwiseAnd5(int m, int n)
{
    int i, x = m ^ n;
    for (i = 0; x != 0; ++i)
        x >>= 1;
    return (n >> i) << i;
}

int rangeBitwiseAnd(int m, int n)
{
    unsigned int x = m ^ n;
    x |= x >> 1, x |= x >> 2, x |= x >> 4, x |= x >> 8, x |= x >> 16;
    return m & ~x;
}

int main()
{
    cout << rangeBitwiseAnd(600000000, 2147483645) << endl;
    return 0;
}

