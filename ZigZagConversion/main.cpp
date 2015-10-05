#include <iostream>

using namespace std;

string convert(string s, int numRows)
{
    if(numRows < 2) return s;
    string zigzag;
    int len = s.size();
    int spread = (numRows - 1) * 2;
    int increment;
    for(int j = 0;j < len;j += spread)
    {
//        zigzag.append(s.substr(j,1));
        zigzag += s[j];
    }
    for(int i = 1;i < numRows - 1;++i)
    {
        increment = 2 * i;
        for(int j = i;j < len;j += increment)
        {
//            zigzag.append(s.substr(j,1));
            zigzag += s[j];
            increment = spread - increment;
        }
    }
    for(int j = numRows - 1;j < len;j += spread)
    {
//        zigzag.append(s.substr(j,1));
        zigzag += s[j];
    }
    return zigzag;
}

int main()
{
    cout << convert("0123456789", 4) << endl;
    cout << convert("PAYPALISHIRING", 3) << endl; //"PAHNAPLSIIGYIR"
    return 0;
}

