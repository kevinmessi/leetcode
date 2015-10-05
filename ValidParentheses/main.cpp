#include <iostream>
#include <stack>

using namespace std;

bool isMatch(char c1, char c2)
{
    if(c1 == '(' && c2 == ')') return true;
    if(c1 == '[' && c2 == ']') return true;
    if(c1 == '{' && c2 == '}') return true;
    return false;
}

bool isValid(string s)
{
    int len = s.size();
    if(len < 1) return true;
    stack<char> parentheses;
    for(int i = 0;i < len;++i)
    {
        if(!parentheses.empty() && isMatch(parentheses.top(),s[i])) parentheses.pop();
        else parentheses.push(s[i]);
    }
    return parentheses.empty();
}

bool isValid2(string s)
{
    stack<char> parentheses;
    for (char& c : s)
    {
        switch (c)
        {
        case '(':
        case '{':
        case '[': parentheses.push(c); break;
        case ')':
            if (parentheses.empty() || parentheses.top() != '(') return false;
            else parentheses.pop();
            break;
        case '}':
            if (parentheses.empty() || parentheses.top() != '{') return false;
            else parentheses.pop();
            break;
        case ']':
            if (parentheses.empty() || parentheses.top() != '[') return false;
            else parentheses.pop();
            break;
        }
    }
    return parentheses.empty() ;
}

int main()
{
    cout << isValid("()[]{}") << endl;
    cout << isValid("([)]") << endl;
    return 0;
}

