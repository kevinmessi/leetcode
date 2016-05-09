#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int hIndex1(vector<int> &citations)
{
    int n = citations.size();
    sort(citations.begin(), citations.end());
    for (int i = 1; i <= n; ++i)
    {
        if (citations[n - i] < i)
            return i - 1;
    }
    return n;
}

int hIndex(vector<int> &citations)
{
    int n = citations.size();
    vector<int> count(n + 1, 0);
    for (int c : citations)
       ++count[c < n ? c : n];
    int sum = 0;
    for (int i = n; i >= 0; --i)
    {
        sum += count[i];
        if (sum >= i) return i;
    }
    return 0;
}

int main()
{
    vector<int> citations { 3, 0, 6, 1, 5 };
    cout << hIndex(citations) << endl;
    return 0;
}
