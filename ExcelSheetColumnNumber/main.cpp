#include <iostream>

using namespace std;

int titleToNumber(string s)
{
    int num = 0;
    int len = s.size();
    for(int i = 0;i < len;++i)
    {
        num = num * 26 + s[i] - 64;
    }
    return num;
}

int main()
{
    cout << titleToNumber("AB") << endl;
    return 0;
}

