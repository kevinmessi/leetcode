#include <iostream>
#include <sstream>
#include <vector>

#include "../toolkit/print.h"

using namespace std;

void restoreIpAddresses(string s, int n, string ip, vector<string> &ips)
{
    if (n == 0)
    {
        ip.erase(ip.end() - 1);
        if (s.empty()) ips.push_back(ip);
        return;
    }
    int len = s.length(), num = 0;
    if (len < n || len > 3 * n) return;
    for (int i = 0; i < min(3, len); ++i)
    {
        num = 10 * num + (s[i] - '0');
        ip += s[i];
        if (num < 256) restoreIpAddresses(s.substr(i + 1, len - i - 1), n - 1, ip + ".", ips);
        if (num == 0) break;
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ips;
    string ip;
    restoreIpAddresses(s, 4, ip, ips);
    return ips;
}

int main()
{
    PrintVector(restoreIpAddresses("010010"));
    PrintVector(restoreIpAddresses("25525511135"));
    return 0;
}

