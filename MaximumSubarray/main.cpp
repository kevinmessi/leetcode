#include <iostream>

using namespace std;

int maxSubArray(int A[], int n)
{
    if(n==0) return 0;
    int n_max=A[0];
    int max=n_max;
    for(int i=1;i<n;i++)
    {
        if(n_max>=0) n_max+=A[i];
        else n_max=A[i];
        if(n_max>max) max=n_max;
    }
    return max;
}

int main()
{
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(a,9) << endl;
    return 0;
}

