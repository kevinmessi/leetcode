#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int longestValidParentheses1(string s)
{
    stack<int> st;
    int len = s.length(), max_len = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '(') st.push(i);
        else
        {
            if (!st.empty() && s[st.top()] == '(')
            {
                st.pop();
                max_len = max(max_len, i - (st.empty() ? -1 : st.top()));
            }
            else st.push(i);
        }
    }
    return max_len;
}

int longestValidParentheses2(string s)
{
    int len = s.length(), max_len = 0;
    vector<int> longest(len, 0);
    for (int i = 1; i < len; ++i)
    {
        if (s[i] == ')')
        {
            int idx = i - longest[i - 1] - 1;
            if (idx >= 0 && s[idx] == '(')
                longest[i] = longest[i - 1] + 2 + (idx > 0 ? longest[idx - 1] : 0);
        }
        max_len = max(max_len, longest[i]);
    }
    return max_len;
}

int longestValidParentheses(string s)
{
    int len = s.length(), extra = 0, valid_len = 0, max_len = 0, right = -1;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '(')
        {
            ++extra;
            ++valid_len;
        }
        else
        {
            if (extra == 0) valid_len = 0;
            else
            {
                --extra;
                ++valid_len;
                if (extra == 0) max_len = max(max_len, valid_len);
            }
        }
        if (extra == 0) right = i;
    }
    extra = valid_len = 0;
    for (int i = len - 1; i > right; --i)
    {
        if (s[i] == ')')
        {
            ++extra;
            ++valid_len;
        }
        else
        {
            if (extra == 0) valid_len = 0;
            else
            {
                --extra;
                ++valid_len;
                if (extra == 0) max_len = max(max_len, valid_len);
            }
        }
    }
    return max_len;
}

int main()
{
    cout << longestValidParentheses("()(()")<< longestValidParentheses("()(())") << endl;
    return 0;
}
