#include <iostream>
#include <sstream>

using namespace std;

string convertToTitle(int n)
{
    string s;
    char c;
    while(n)
    {
        --n;
        c = n % 26 + 'A';
        s = c + s;
        n /= 26;
    }
    return s;
}

int main()
{
    cout << convertToTitle(26) << endl;
    return 0;
}

