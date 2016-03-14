#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n)
{
    int i2 = 0, i3 = 0, i5 = 0;
    vector<int> u(n);
    u[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        u[i] = min(2 * u[i2], min(3 * u[i3], 5 * u[i5]));
        if (u[i] == 2 * u[i2]) ++i2;
        if (u[i] == 3 * u[i3]) ++i3;
        if (u[i] == 5 * u[i5]) ++i5;
    }
    return u[n - 1];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

