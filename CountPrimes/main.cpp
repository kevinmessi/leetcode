#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;

void PrintVector(vector<int> v)
{
    int len = v.size();
    for(int i = 0;i < len;++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int sqrt(int n)
{
    int i = 0;
    while(i*i <= n)
    {
        ++i;
    }
    return i - 1;
}

int countPrimes(int n)
{
    if(n < 3) return 0;
//    vector<bool> flag(n, true);
    bool *flag = new bool[n];
    for(int i = 3;i < n;i += 2)
    {
        flag[i] = true;
    }
    int sq = sqrt(n);
    int count = 1;
    for(int i = 3;i < n;i += 2)
    {
        if(flag[i])
        {
            ++count;
            if(i <= sq)
            {
                for(int j = i*i, k = i << 1;j < n;j += k)
                {
                    flag[j] = false;
                }
            }
        }
    }
    delete[] flag;
    return count;
}

int main()
{
    cout << countPrimes(3000000) << endl;
    return 0;
}

