#include <iostream>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0) return "0";
    long long n = llabs(numerator), d = llabs(denominator);
    string quotient = (((numerator < 0) ^ (denominator < 0)) ? "-" : "") + to_string(n / d);
    n %= d;
    if (n) quotient.append(1, '.');
    unordered_map<int, int> table;
    while (table.find(n) == table.end() && n!= 0)
    {
        table[n] = quotient.size();
        n *= 10;
        quotient.append(1, n / d + '0');
        n %= d;
    }
    if (table.find(n) != table.end())
    {
        quotient.insert(table[n], 1, '(');
        quotient.append(1, ')');
    }
    return quotient;
}

int main()
{
    cout << fractionToDecimal(1, 2) << endl;
    cout << fractionToDecimal(2, 1) << endl;
    cout << fractionToDecimal(2, 3) << endl;
    cout << fractionToDecimal(4, 9) << endl;
    cout << fractionToDecimal(4, 333) << endl;
    cout << fractionToDecimal(-2147483648, -1) << endl;
    return 0;
}
