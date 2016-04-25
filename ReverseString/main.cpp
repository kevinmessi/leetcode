#include <iostream>
#include <string>

using namespace std;

string reverseString(string s)
{
    int len = s.length();
    string r(s);
    for (int i = 0, j = len - 1; i < j; ++i, --j)
        swap(r[i], r[j]);
    return r;
}

int main()
{
    cout << reverseString("Hello World!") << endl;
    return 0;
}

