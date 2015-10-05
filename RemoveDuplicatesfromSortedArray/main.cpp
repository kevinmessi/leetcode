#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
    if(n == 0) return 0;
    int m = 1;
    for(int i = 1;i < n;++i)
    {
        if(A[i] != A[m-1]) A[m++] = A[i];
    }
    return m;
}

int main()
{
    int a[] = {1, 1, 2, 2, 3, 4, 4, 4, 5};
    int len = removeDuplicates(a, 9);
    cout << len << endl;
    for(int i = 0;i < len;++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

