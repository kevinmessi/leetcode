#include <iostream>

using namespace std;

void PrintArray(int X[], int length)
{
    for(int i=0;i<length;i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

void merge(int A[], int m, int B[], int n)
{
    int i=m-1,j=n-1,l=m+n-1;
    while(j>=0)
    {
        if(i<0)
        {
            while(j>=0)
            {
                A[j]=B[j];
                j--;
            }
            break;
        }

        if(A[i]>B[j])
        {
            A[l]=A[i];
            i--;
        }
        else
        {
            A[l]=B[j];
            j--;
        }
        l--;
    }
}

int main()
{
    int a[] = {11,13,15,17,19,0,0,0,0};
    int b[] = {2,4,6,8};
    merge(a,5,b,4);
    PrintArray(a,9);
    return 0;
}

