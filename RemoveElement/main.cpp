#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem)
{

    int last=n-1;
    for(int i=0;i<=last;)
    {
        if(A[i]==elem) A[i]=A[last--];
        else ++i;
    }
    return last+1;

    //    int next = 0;
    //    for(int i = 0; i < n; i++)
    //    {
    //        if(A[i]!=elem && i!=next++) A[next-1]=A[i];
    //    }
    //    return next;
}

int main()
{
    int a[]={0,0,0,0,0,0,0,0,0,0,7};
    cout << removeElement(a,11,0) << endl;
    return 0;
}

