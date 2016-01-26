#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string intToRoman1(int num)
{
    string thousands[4] = {"", "M", "MM", "MMM"};
    string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

string intToRoman2(int num)
{
    if (num < 0 || num > 3999) return "";
    stringstream ss;
    string c = "MDCLXVI";
    int digit;
    for (int i = 0, decimal = 1000; num > 0; i += 2, decimal /= 10)
    {
        digit = num / decimal;
        num -= digit * decimal;
        if (digit <= 0)
            continue;
        if (digit <= 3)
            while (digit--) ss << c[i];
        else if (digit == 4)
            ss << c[i] << c[i-1];
        else if (digit <= 8)
        {
            ss << c[i-1];
            while (digit-- > 5) ss << c[i];
        }
        else
            ss << c[i] << c[i-2];
    }
    return ss.str();
}

string intToRoman(int num)
{
    int values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string strs[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    stringstream ss;
    for(int i = 0; i < 13; ++i)
    {
        while(num >= values[i])
        {
            num -= values[i];
            ss << strs[i];
        }
    }
    return ss.str();
}

int main()
{
    cout << intToRoman(5) << endl;
    return 0;
}

