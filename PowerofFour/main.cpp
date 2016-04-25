#include <iostream>

using namespace std;

bool isPowerOfFour1(int num)
{
    return num > 0 && !(num & (num - 1)) && !((num - 1) % 3);
}

bool isPowerOfFour(int num)
{
    return num > 0 && !(num & (num - 1)) && (num & 0x55555555);
}

int main()
{
    cout << isPowerOfFour(256) << isPowerOfFour(128) << endl;
    return 0;
}
