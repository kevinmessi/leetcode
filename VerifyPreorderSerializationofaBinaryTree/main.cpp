#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

bool isValidSerialization1(string preorder)
{
    stack<string> s;
    stringstream ss(preorder);
    string node;
    while (getline(ss, node, ','))
    {
        while (node == "#" && !s.empty() && s.top() == "#")
        {
            s.pop();
            if (s.empty()) return false;
            s.pop();
        }
        s.push(node);
    }
    return s.size() == 1 && s.top() == "#";
}

bool isValidSerialization2(string preorder)
{
    vector<string> v;
    stringstream ss(preorder);
    string node;
    while (getline(ss, node, ','))
        v.push_back(node);
    int len = v.size(), depth = 0;
    for (int i = 0; i < len - 1; ++i)
    {
        if (v[i] == "#")
        {
            if (depth == 0) return false;
            else --depth;
        }
        else ++depth;
    }
    return depth == 0 && v.back() == "#";
}

bool isValidSerialization(string preorder)
{
    stringstream ss(preorder);
    string node;
    int diff = 1;
    while (getline(ss, node, ','))
    {
        if (--diff < 0) return false;
        if (node != "#") diff += 2;
    }
    return diff == 0;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

