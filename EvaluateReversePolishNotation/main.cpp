#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool is_integer(const string &s)
{
    if (s.empty()) return false;
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

int evalRPN1(vector<string>& tokens)
{
    stack<int> notations;
    for (const string &token : tokens)
    {
        if (is_integer(token)) notations.push(atoi(token.c_str()));
        else
        {
            int right = notations.top();
            notations.pop();
            int left = notations.top();
            notations.pop();
            if (token == "+") notations.push(left + right);
            else if (token == "-") notations.push(left - right);
            else if (token == "*") notations.push(left * right);
            else if (token == "/") notations.push(left / right);
            else return 0;
        }
    }
    return notations.top();
}

int evalRPN(vector<string>& tokens)
{
    stack<int> notations;
    for (const string &token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int right = notations.top();
            notations.pop();
            int left = notations.top();
            notations.pop();
            if (token == "+") notations.push(left + right);
            else if (token == "-") notations.push(left - right);
            else if (token == "*") notations.push(left * right);
            else notations.push(left / right);
        }
        else
        {
            notations.push(atoi(token.c_str()));
        }
    }
    return notations.top();
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

