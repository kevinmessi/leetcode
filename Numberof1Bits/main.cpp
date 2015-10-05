#include <iostream>

using namespace std;

typedef unsigned int uint32_t;

int hammingWeight(uint32_t n)
{
    uint32_t m =1;
    int count = 0;
    for(int i = 0;i < 32;i++)
    {
        if(m & n) count++;
        m = m << 1;
    }
    return count;
}

int main()
{
    cout << hammingWeight(11) << endl;
    return 0;
}

