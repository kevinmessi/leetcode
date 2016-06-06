#include <iostream>

using namespace std;

bool isNumber(string s)
{
    const char *c = s.c_str();
    int i = 0;
    for (; c[i] == ' '; ++i)
        ;
    if (c[i] == '+' || c[i] == '-') ++i;
    int num_cnt = 0, dot_num = 0;
    for (; isdigit(c[i]) || c[i] == '.'; ++i)
        c[i] == '.' ? ++dot_num : ++num_cnt;
    if (dot_num > 1 || num_cnt == 0) return false;
    if (s[i] == 'e')
    {
        ++i;
        if (c[i] == '+' || c[i] == '-') ++i;
        int num_cnt = 0;
        for (; isdigit(c[i]); ++i, ++num_cnt)
            ;
        if (num_cnt == 0) return false;
    }
    for (; c[i] == ' '; ++i)
        ;
    return c[i] == '\0';
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
