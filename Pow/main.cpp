#include <iostream>

using namespace std;

double pow(double x, int n)
{
    if(n<0)
    {
        x=1/x;
        n=-n;
    }
    double tmp = x, ret = 1.0;
    for(int t=n; t>0; t/=2)
    {
        if(t%2==1) ret*=tmp;
        tmp = tmp * tmp;
    }
    return ret;
}

int main()
{
    cout << pow(0.0001,2147483647) << endl;
    return 0;
}
