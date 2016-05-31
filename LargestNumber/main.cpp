#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

string largestNumber(vector<int> &nums)
{
    if (nums.empty()) return "";
    vector<string> str_nums;
    for (int n : nums)
        str_nums.push_back(to_string(n));
    auto comp = [](const string &s1, const string &s2)
    {
        return s1 + s2 > s2 + s1;
    };
    sort(str_nums.begin(), str_nums.end(), comp);
    string number;
    for (const string &str : str_nums)
        number.append(str);
    return number[0] == '0' ? "0" : number;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
