#include <iostream>

using namespace std;

int sqrt(int x)
{
    if(x<=1) return x;
    int left=0,right=x;
    while(right-left > 1)
    {
        int middle=(left+right)/2;
        if(middle <= x/middle) left=middle;
        else right=middle;
    }
    return left;
}

int main()
{
    //int x;
    //cin >> x;
    //cout << sqrt(x) << endl;
    cout << sqrt(2147395599) << endl;
    return 0;
}

