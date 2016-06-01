#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int integerBreak1(int n)
{
    vector<int> products(n + 1);
    products[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = i / 2; j >= 1; --j)
            products[i] = max(products[i], max(j, products[j]) * max(i - j, products[i - j]));
    }
    return products[n];
}

int integerBreak2(int n)
{
    if (n == 2) return 1;
    if (n == 3) return 2;
    int product = 1;
    while (n > 4)
    {
        product *= 3;
        n -= 3;
    }
    product *= n;
    return product;
}

int integerBreak(int n)
{
    if (n == 2) return 1;
    if (n == 3) return 2;
    int remainder = n % 3, exponent = n / 3;
    if (remainder == 0) return (int)pow(3, exponent);
    if (remainder == 1) return 4 * (int)pow(3, exponent - 1);
    return 2 * (int)pow(3, exponent);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
