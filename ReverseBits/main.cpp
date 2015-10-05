#include <iostream>

using namespace std;

typedef unsigned int uint32_t;

uint32_t reverseBits(uint32_t n)
{
    uint32_t r = 0;
    uint32_t bit = 0;
    for(int i = 0;i < 32;i++)
    {
        bit = n % 2;
        r = (r << 1) + bit;
        n = n >> 1;
    }
    return r;
}

int main()
{
    cout << reverseBits(1) << endl;
    return 0;
}

