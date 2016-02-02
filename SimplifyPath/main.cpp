#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

string simplifyPath1(string path)
{
    stack<string> paths;
    string dir;
    path += "/";
    for (char c : path)
    {
        if (c == '/')
        {
            if (dir == "..")
            {
                if (!paths.empty()) paths.pop();
            }
            else if (dir != "." && !dir.empty())
            {
                paths.push("/" + dir);
            }
            dir.clear();
        }
        else
        {
            dir += c;
        }
    }
    if (paths.empty()) return "/";
    string simple_path;
    while (!paths.empty())
    {
        simple_path = paths.top() + simple_path;
        paths.pop();
    }
    return simple_path;
}

string simplifyPath2(string path)
{
    vector<string> paths;
    string dir;
    path += "/";
    for (char c : path)
    {
        if (c == '/')
        {
            if (dir == "..")
            {
                if (!paths.empty()) paths.pop_back();
            }
            else if (dir != "." && !dir.empty())
            {
                paths.push_back("/" + dir);
            }
            dir.clear();
        }
        else
        {
            dir += c;
        }
    }
    string simple_path;
    for (const string &s : paths)
        simple_path += s;
    return paths.empty() ? "/" : simple_path;
}

string simplifyPath(string path)
{
    string simple_path, dir;
    stringstream ss(path);
    vector<string> paths;
    while (getline(ss, dir, '/'))
    {
        if (dir == "." || dir.empty()) continue;
        else if (dir == "..")
        {
            if (!paths.empty()) paths.pop_back();
        }
        else paths.push_back("/" + dir);
    }
    for (const string &s : paths)
        simple_path += s;
    return paths.empty() ? "/" : simple_path;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

