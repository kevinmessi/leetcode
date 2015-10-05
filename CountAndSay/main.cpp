//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...

//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.

//Note: The sequence of integers will be represented as a string.

#include <iostream>
#include <algorithm>

using namespace std;

string nextCountAndSay(string num)
{
    string next;
    int start = 0;
    int len = num.length();
    for(int i = 0;i < len - 1;++i)
    {
        if(num[i] != num[i+1])
        {
            next += '0' + (i - start + 1);
            next += num[i];
            start = i + 1;
        }
    }
    next += '0' + (len - start);
    next += num[len-1];
    return next;
}

string next( const string& val)
{
    string result;
    for (auto left_bound = val.cbegin();left_bound != val.cend();)
    {
        auto right_bound = find_if(left_bound, val.cend(), bind2nd(not_equal_to<char>(), *left_bound));
        result += '0' + (right_bound - left_bound);
        result += *left_bound;
        left_bound = right_bound;
    }
    return result;
}

string countAndSay(int n)
{
    if(n < 1) return "";
    string num = "1";
    for(int i = 1;i < n;++i)
    {
        cout << num << endl;
        num = next(num);
    }
    return num;
}

int main()
{
    cout << countAndSay(20) << endl;
    return 0;
}

