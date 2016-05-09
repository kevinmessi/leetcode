#include <iostream>
#include <vector>

using namespace std;

int hIndex1(vector<int> &citations)
{
    int n = citations.size();
    for (int i = 1; i <= n; ++i)
    {
        if (citations[n - i] < i)
            return i - 1;
    }
    return n;
}

int hIndex(vector<int> &citations)
{
    int n = citations.size(), L = 0, R = n;
    while (L < R)
    {
        int M = L + (R - L) / 2;
        if (citations[M] < n - M) L = M + 1;
        else R = M;
    }
    return n - L;
}

int main()
{
    vector<int> citations { 0, 1, 2, 5, 6 };
    cout << hIndex(citations) << endl;
    return 0;
}
