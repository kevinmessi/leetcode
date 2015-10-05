#include <iostream>

using namespace std;

int addDigits(int num)
{
    return 1 + (num - 1) % 9;
}

int main()
{
    for(int i = 0;i < 30;++i)
    {
        cout << addDigits(i) << endl;
    }
    cout << -1 % 9 << endl;
    return 0;
}
