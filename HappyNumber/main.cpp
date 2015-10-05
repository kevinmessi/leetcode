#include <iostream>
#include <set>

using namespace std;

//bool isHappy(int n)
//{
//    set<int> s;
//    while(n != 1)
//    {
//        if(s.end() != s.find(n)) return false;
//        s.insert(n);
//        int sum = 0;
//        while(n >= 1)
//        {
//            int d = n % 10;
//            sum += d * d;
//            n /= 10;
//        }
//        n = sum;
//    }
//    return true;
//}

//bool isHappy(int n)
//{
//    if (n <= 0) return false;
//    int magic = 4;
//    while(true)
//    {
//        if (n == 1) return true;
//        if (n == magic) return false;
//        int t = 0;
//        while(n)
//        {
//            t += (n % 10) * (n % 10);
//            n /= 10;
//        }
//        n = t;
//    }
//}

int squareSum(int n)
{
    int sum = 0;
    while(n >= 1)
    {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow = n,fast = n;
    while(true)
    {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
        if(slow == 1) return true;
        if(slow == fast) return false;
    }
}

int main()
{
    cout << isHappy(19) << endl;
    return 0;
}

