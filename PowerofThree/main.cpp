#include <iostream>

using namespace std;

bool isPowerOfThree1(int n)
{
    while (n >= 3)
    {
        if (n % 3 != 0) return false;
        n /= 3;
    }
    return n == 1;
}

bool isPowerOfThree2(int n)
{
    int i = 1, upper = INT_MAX / 3;
    while (n > i && i <= upper)
        i += i << 1;
    return n == i;
}

bool isPowerOfThree(int n)
{
    return (n > 0) && (1162261467 % n == 0);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

