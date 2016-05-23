#include <iostream>
#include <stack>

using namespace std;

int calculate(string s)
{
    stack<int> st;
    int result = 0, sign = 1, num = 0;
    for (char c : s)
    {
        if (isdigit(c)) num = 10 * num + c - '0';
        else
        {
            result += sign * num;
            if (c == '+') sign = 1;
            else if (c == '-') sign = -1;
            else if (c == '(')
            {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
            num = 0;
        }
    }
    return result + sign * num;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
