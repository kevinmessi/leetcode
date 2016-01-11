#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int len = nums.size();
    int one = 0, two = 0;
    for(int i = 0; i < len; ++i)
    {
        one = (one ^ nums[i]) & ~two;
        two = (two ^ nums[i]) & ~one;
    }
    return one;
}

int singleNumber(int A[], int n)
{
    int na = 0, nb = 0, nc = 0;
    for(int i = 0; i < n; i++)
    {
        nb = nb ^ (A[i] & na);
        na = (na ^ A[i]) & ~nc;
        nc = nc ^ (A[i] & ~na & ~nb);
    }
    return na;
}

int main()
{
    vector<int> v = { 3, 3, 1, 2, 1, 1, 3 };
    cout << singleNumber(v) << endl;
    int A[] = { 4, 4, 1, 4, 1, 1, 4, 1, 4, 1, 3 };
    cout << singleNumber(A, 11) << endl;
    return 0;
}

