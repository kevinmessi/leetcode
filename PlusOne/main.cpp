#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> v)
{
    for(auto i:v) cout << i;
    cout<<endl;
}

vector<int> plusOne(vector<int> &digits)
{
    int cursor = (int) digits.size() - 1;
    vector<int> sum(cursor+1);
    int carry = 1;
    while(cursor >= 0)
    {
        int temp = digits[cursor] + carry;
        if(temp > 9)
        {
            carry = 1;
            temp = 0;
        }
        else carry = 0;
        sum[cursor] = temp;
        cursor--;
    }
    if(carry == 1) sum.insert(sum.begin(),1);
    return sum;
}

int main()
{
    //vector<int> v(9,9);
    vector<int> v{9,9,9,9,9,9,9,9,9};
    PrintVector(plusOne(v));
    return 0;
}

