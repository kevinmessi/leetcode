#include <iostream>

using namespace std;

int climbStairs(int n)
{
    if (n == 1 || n == 2) return n;
    int first = 1;
    int second = 2;
    for (int i = 3;i <= n;i++)
    {
        int temp = first;
        first = second;
        second = temp + second;
    }
    return second;
}

int main()
{
    cout << climbStairs(45) << endl;
    return 0;
}

