#include <stdlib.h>
#include <iostream>

using namespace std;

int compareString(string s1, string s2)
{
    int is1 = atoi(s1.c_str()), is2 = atoi(s2.c_str());
    if(is1 > is2) return 1;
    else if(is1 < is2) return -1;
    else return 0;
}

int compareVersion(string version1, string version2)
{
    while(true)
    {
        cout << version1 << " " << version2 << endl;

        int p1 = version1.find('.'), p2 = version2.find('.');
        int r = compareString(version1.substr(0,p1), version2.substr(0,p2));
        if(r != 0) return r;
        if(p1 < 0 && p2 < 0) return 0;
        if(p1 < 0) version1="0";
        else version1 = version1.substr(p1+1,version1.size()-p1-1);
        if(p2 < 0) version2="0";
        else version2 = version2.substr(p2+1,version2.size()-p2-1);
    }
}

int main()
{
    string s = "1";
    //0.1 < 1.1 < 1.2 < 13.37
    cout << "result: " << compareVersion("2.0.0.0","2") << endl;
    //cout << s.substr(2,-1) << endl;
    return 0;
}

