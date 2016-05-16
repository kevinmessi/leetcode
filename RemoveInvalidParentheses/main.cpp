#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

bool IsValid(string s)
{
    int count = 0;
    for (char c: s)
    {
        if (c == '(') ++count;
        else if (c == ')')
        {
            if (count > 0) --count;
            else return false;
        }
    }
    return count == 0;
}

vector<string> removeInvalidParentheses1(string s)
{
    vector<string> result;
    queue<string> q;
    unordered_set<string> visited;
    bool found = false;
    q.push(s);
    visited.insert(s);
    while (!q.empty())
    {
        string p = q.front();
        q.pop();
        if (IsValid(p))
        {
            result.push_back(p);
            found = true;
        }
        if (found) continue;
        int len = p.length();
        for (int i = 0; i < len; ++i)
        {
            if (p[i] != '(' && p[i] != ')') continue;
            string r = p.substr(0, i) + p.substr(i + 1);
            if (visited.find(r) == visited.end())
            {
                q.push(r);
                visited.insert(r);
            }
        }
    }
    return result;
}

void removeInvalidParentheses(const string &s, size_t idx, int left, int right, int open, string &ps, unordered_set<string> &result)
{
    if (idx == s.length() || left < 0 || right < 0 || open < 0)
    {
        if (idx == s.length() && left == 0 && right == 0 && open == 0) result.insert(ps);
        return;
    }
    if (s[idx] == '(')
    {
        removeInvalidParentheses(s, idx + 1, left - 1, right, open, ps, result);
        removeInvalidParentheses(s, idx + 1, left, right, open + 1, ps.append(1, s[idx]), result);
    }
    else if (s[idx] == ')')
    {
        removeInvalidParentheses(s, idx + 1, left, right - 1, open, ps, result);
        removeInvalidParentheses(s, idx + 1, left, right, open - 1, ps.append(1, s[idx]), result);
    }
    else
    {
        removeInvalidParentheses(s, idx + 1, left, right, open, ps.append(1, s[idx]), result);
    }
    ps.erase(ps.end() - 1);
}

vector<string> removeInvalidParentheses2(string s)
{
    unordered_set<string> result;
    int left = 0, right = 0;
    for (char c : s)
    {
        if (c == '(') ++left;
        else if (c == ')')
        {
            if (left > 0) --left;
            else ++right;
        }
    }
    string ps;
    removeInvalidParentheses(s, 0, left, right, 0, ps, result);
    return vector<string>(result.begin(), result.end());
}

void removeInvalidParentheses(string s, int last_i, int last_j, char p1, char p2, vector<string> &result)
{
    int len = s.length();
    for (int count = 0, i = last_i; i < len; ++i)
    {
        if (s[i] == p1) ++count;
        else if (s[i] == p2) --count;
        if (count >= 0) continue;
        for (int j = last_j; j <= i; ++j)
        {
            if (s[j] == p2 && (j == last_j || s[j - 1] != p2))
                removeInvalidParentheses(s.substr(0, j) + s.substr(j + 1), i, j, p1, p2, result);
        }
        return;
    }
    reverse(s.begin(), s.end());
    if (p1 == '(')
        removeInvalidParentheses(s, 0, 0, ')', '(', result);
    else
        result.push_back(s);
}

vector<string> removeInvalidParentheses(string s)
{
    vector<string> result;
    removeInvalidParentheses(s, 0, 0, '(', ')', result);
    return result;
}

int main()
{
    PrintVector(removeInvalidParentheses("()())()"));
    PrintVector(removeInvalidParentheses("(a)())()"));
    PrintVector(removeInvalidParentheses(")("));
    return 0;
}
