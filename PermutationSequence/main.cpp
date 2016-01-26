#include <iostream>
#include <vector>

using namespace std;

string getPermutation1(int n, int k)
{
    string s;
    vector<char> nums(n);
    int factorial = 1;
    for (int i = 0; i < n; ++i)
    {
        nums[i] = i + '1';
        factorial *= i + 1;
    }
    while (n > 0)
    {
        factorial /= n;
        int idx = (k - 1) / factorial;
        s += nums[idx];
        nums.erase(nums.begin() + idx);
        k -= idx * factorial;
        --n;
    }
    return s;
}

string getPermutation(int n, int k)
{
    string s(n, '0');
    int factorial = 1;
    for (int i = 0; i < n; ++i)
    {
        s[i] += i + 1;
        factorial *= i + 1;
    }
    for (int i = 0; i < n; ++i)
    {
        factorial /= n - i;
        int idx = (k - 1) / factorial + i;
        k -= (idx - i) * factorial;
        char temp = s[idx];
        for (; idx > i; --idx)
            s[idx] = s[idx - 1];
        s[i] = temp;
    }
    return s;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

