#include <iostream>

using namespace std;

int lengthOfLastWord(const char *s)
{
    string ss = s;
    int begin, end;
    for(end = ss.size()-1;end >= 0;--end)
    {
        if(ss[end] != ' ') break;
    }
    for(begin = end;begin >= 0;--begin)
    {
        if(ss[begin] == ' ')  break;
    }
    begin++;
    return end - begin + 1;
}

int main()
{
    cout << lengthOfLastWord("Hello World") << endl;
    return 0;
}

