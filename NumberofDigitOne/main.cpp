#include <iostream>

using namespace std;

int countDigitOne(int n)
{
    int ones = 0, decimal = 1, tail = 0;
    while (n > 0)
    {
        int d = n % 10;
        n /= 10;
        ones += n * decimal + (d > 1 ? decimal : (d == 1 ? tail + 1 : 0));
        if (n == 0) break;
        tail += decimal * d;
        decimal *= 10;
    }
    return ones;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

