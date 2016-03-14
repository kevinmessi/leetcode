#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    vector<int> singles{ 0, 0 };
    int num = 0;
    for (int n : nums)
        num ^= n;
    num &= -num;
    for (int n : nums)
        singles[!(n & num)] ^= n;
    return singles;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

