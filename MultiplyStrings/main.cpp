#include <iostream>

using namespace std;

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";
    string product;
    int n1 = num1.length(), n2 = num2.length();
    int carry = 0;
    for (int i = n1 + n2 - 2; i >= 0; --i)
    {
        int digit = carry;
        for (int j = min(i, n2 - 1); j >= max(i - n1 + 1, 0); --j)
            digit += (num1[i - j] - '0') * (num2[j] - '0');
        product = (char)(digit % 10 + '0') + product;
        carry = digit / 10;
    }
    if (carry > 0)
        product = (char)(carry + '0') + product;
    return product;
}

int main()
{
    cout << multiply("234323412", "13413411") << endl;
    return 0;
}

