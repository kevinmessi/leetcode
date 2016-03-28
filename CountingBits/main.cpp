#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits1(int num)
{
    vector<int> bits(num + 1);
    bits[0] = 0;
    for (int i = 1; i <= num; ++i)
        bits[i] = bits[i >> 1] + (i & 1);
    return bits;
}

vector<int> countBits2(int num)
{
    vector<int> bits(num + 1);
    bits[0] = 0;
    for (int i = 1; i <= num; ++i)
        bits[i] = bits[i & (i - 1)] + 1;
    return bits;
}

vector<int> countBits(int num)
{
    vector<int> bits(num + 1);
    bits[0] = 0;
    for (int n = 1; n <= num; n <<= 1)
    {
        for (int i = 0; i < n && n + i <= num; ++i)
            bits[n + i] = bits[i] + 1;
    }
    return bits;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

