#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target)
{
    int left=-1,right=n;
    while(right-left>1)
    {
        int middle=(left+right)/2;
        if(A[middle]>=target) right=middle;
        else left=middle;
    }
    return right;
}

int main()
{
    int a[]={1,3,5,6,7};
    cout << searchInsert(a,5,8) << endl;
    return 0;
}

