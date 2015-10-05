#include <iostream>

using namespace std;

int singleNumber(int A[], int n)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        x=x^A[i];
    }
    return x;
}

int main()
{
    int a[]={9, 4, 7, 9, 3, 7, 4, 5, 3};
    cout << singleNumber(a,9) <<endl;
    return 0;
}
