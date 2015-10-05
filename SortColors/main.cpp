#include <iostream>

using namespace std;

void PrintArray(int A[], int n)
{
    for(int i=0;i<n;++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void sortColors(int A[], int n)
{
    int white = 0;
    for(int i = 0;i < n;++i)
    {
        if(A[i] == 0)
        {
            A[i] = A[white];
            A[white++] = 0;
        }
        else if(A[i] == 2)
        {
            A[i--] = A[--n];
            A[n] = 2;
        }
    }
}

int main()
{
    int a[] = {0,1,0,2,1,1,0,2,1,0};
    sortColors(a,10);
    PrintArray(a,10);
    return 0;
}

