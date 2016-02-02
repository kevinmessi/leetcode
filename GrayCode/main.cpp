#include <iostream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void grayCode1(int n, vector<int> &codes)
{
    if (n == 0)
    {
        codes.push_back(0);
        return;
    }
    grayCode1(n - 1, codes);
    for (int i = codes.size() - 1; i >= 0; --i)
        codes.push_back((1 << (n - 1)) + codes[i]);
}

vector<int> grayCode1(int n)
{
    vector<int> codes;
    grayCode1(n, codes);
    return codes;
}

vector<int> grayCode2(int n)
{
    vector<int> codes(1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = codes.size() - 1; j >= 0; --j)
            codes.push_back((1 << i) + codes[j]);
    return codes;
}

vector<int> grayCode(int n)
{
    vector<int> codes(1 << n);
    for (int i = 0; i < 1 << n; ++i)
        codes[i] = i ^ (i >> 1);
    return codes;
}

int main()
{
    PrintVector(grayCode2(3));
    return 0;
}

