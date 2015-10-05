#include <iostream>

using namespace std;

bool isBadVersion(int version)
{
    if(version >= 1702766719)
        return true;
    return false;
}

int firstBadVersion(int n)
{
    int begin = 1;
    while(begin < n)
    {
        int middle = begin + (n - begin) / 2;
        if(isBadVersion(middle))
            n = middle;
        else
            begin = middle + 1;
    }
    return n;
}

int main()
{
    cout << firstBadVersion(2126753390) << endl;
    return 0;
}

