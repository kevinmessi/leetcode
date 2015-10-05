#include <iostream>

using namespace std;

// https://leetcode.com/discuss/25593/short-code-by-c
string addBinary(string a, string b)
{
    string s = "";
    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? a[i--] - '0' : 0;
        c += j >= 0 ? b[j--] - '0' : 0;
        s.insert(s.begin(), (c & 1) + '0');
        c = c >> 1;
    }
    return s;
}

string _addBinary_(string a, string b)
{
    string sum;
    int na = a.size(), nb = b.size();
    int n = min(na, nb);
    int k = 0, p;
    for(int i = 0;i < n;++i)
    {
        p = a[na - i - 1] - '0' + b[nb - i - 1] - '0' + k;
        k = p >> 1;
        sum.insert(sum.begin(), (p & 1) + '0');
    }
    if(na < nb)
    {
        a = b;
        na = nb;
    }
    for(int i = n;i < na;++i)
    {
        p = a[na - i - 1] - '0' + k;
        k = p >> 1;
        sum.insert(sum.begin(), (p & 1) + '0');
    }
    if(k) sum.insert(sum.begin(), k +'0');
    return sum;
}

int main()
{
    cout << addBinary("11", "11") << endl;
    return 0;
}

