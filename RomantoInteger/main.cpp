#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt3(string s)
{
    int len = s.length();
    int symbol[100] = {0};
    symbol['I'] = 1;
    symbol['V'] = 5;
    symbol['X'] = 10;
    symbol['L'] = 50;
    symbol['C'] = 100;
    symbol['D'] = 500;
    symbol['M'] = 1000;
    int num = symbol[s[0]];
    for(int i = 1;i < len;++i)
    {
        num += symbol[s[i]];
        if(symbol[s[i]] > symbol[s[i-1]])
        {
            num -= 2 * symbol[s[i-1]];
        }
    }
    return num;
}

int romanToInt2(string s)
{
    int sum = 0;
    int len = s.length();
    int symbol[100] = {0};
    symbol['I'] = 1;
    symbol['V'] = 5;
    symbol['X'] = 10;
    symbol['L'] = 50;
    symbol['C'] = 100;
    symbol['D'] = 500;
    symbol['M'] = 1000;
    for(int i = 0;i < len;++i)
    {
        sum += symbol[s[i]];
    }
    if(s.find("IV") != -1) sum -= 2;
    if(s.find("IX") != -1) sum -= 2;
    if(s.find("XL") != -1) sum -= 20;
    if(s.find("XC") != -1) sum -= 20;
    if(s.find("CD") != -1) sum -= 200;
    if(s.find("CM") != -1) sum -= 200;
    return sum;
}

int romanToInt(string s)
{
    int len = s.length();
    int num = 0;
    int last = 0;
    for(int i = 0;i < len;++i)
    {
        int value = 0;
        switch(s[i])
        {
        case 'I': value = 1; break;
        case 'V': value = 5; break;
        case 'X': value = 10; break;
        case 'L': value = 50; break;
        case 'C': value = 100; break;
        case 'D': value = 500; break;
        case 'M': value = 1000; break;
        }
        num += value;
        if(value > last) num -= 2 * last;
        last = value;
    }
    return num;
}

int main()
{
    cout << romanToInt("MCMLXXX") << endl;    //1980
    cout << romanToInt("MCMLXXVI") << endl;   //1976
    cout << romanToInt("MMMCMXCIX") << endl;  //3999
    return 0;
}
