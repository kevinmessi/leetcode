#include <iostream>

using namespace std;

bool isAdditiveNumber(const string &num, int idx, long long pre2, long long pre1, int count)
{
    int len = num.length();
    if (idx == len && count >= 3) return true;
    long long int n = 0;
    for (int i = idx; i < len; ++i)
    {
        n = 10 * n + num[i] - '0';
        if (pre2 < 0 || pre1 < 0 || pre1 + pre2 == n)
        {
            if (isAdditiveNumber(num, i + 1, pre1, n, count + 1))
                return true;
        }
        if (num[idx] == '0') return false;
    }
    return false;
}

bool isAdditiveNumber1(string num)
{
    return isAdditiveNumber(num, 0, -1, -1, 0);
}

bool isAdditiveNumber(string num)
{
    int len = num.length();
    long long pre2 = 0;
    for (int i = 0; i < len - 2; ++i)
    {
        pre2 = 10 * pre2 + num[i] - '0';
        long long pre1 = 0;
        for (int j = i + 1; j < len - 1; ++j)
        {
            pre1 = 10 * pre1 + num[j] - '0';
            long long p2 = pre2, p1 = pre1;
            int k = j + 1;
            while (k < len)
            {
                long long p0 = num[k] - '0';
                while (++k < len && p0 && p0 < p1 + p2)
                    p0 = 10 * p0 + num[k] - '0';
                if (p0 != p1 + p2) break;
                if (k == len) return true;
                p2 = p1;
                p1 = p0;
            }
            if (num[i + 1] == '0') break;
        }
        if (num[0] == '0') break;
    }
    return false;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
