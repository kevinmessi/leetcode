#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int nthSuperUglyNumber1(int n, vector<int> &primes)
{
    int k = primes.size();
    vector<int> u(n), indices(k, 0);
    u[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        u[i] = primes[0] * u[indices[0]];
        for (int j = 1; j < k; ++j)
            u[i] = min(u[i], primes[j] * u[indices[j]]);
        for (int j = 0; j < k; ++j)
        {
            if (u[i] == primes[j] * u[indices[j]])
                ++indices[j];
        }
    }
    return u[n - 1];
}

int nthSuperUglyNumber2(int n, vector<int> &primes)
{
    int k = primes.size(), next = 1;
    vector<int> u(n), indices(k, 0), products(k, 1);
    for (int i = 0; i < n; ++i)
    {
        u[i] = next;
        next = INT_MAX;
        for (int j = 0; j < k; ++j)
        {
            if (u[i] == products[j])
                products[j] = primes[j] * u[indices[j]++];
            next = min(next, products[j]);
        }
    }
    return u[n - 1];
}

struct Num
{
    int val, idx, prime;
    Num(int v, int i, int p) : val(v), idx(i), prime(p) {}
    inline bool operator < (const Num &n) const
    {
        return val > n.val;
    }
};

int nthSuperUglyNumber(int n, vector<int> &primes)
{
    vector<int> u(n);
    priority_queue<Num> pq;
    for (int p : primes)
        pq.push(Num(1, 0, p));
    for (int i = 0; i < n; ++i)
    {
        u[i] = pq.top().val;
        while (pq.top().val == u[i])
        {
            Num num = pq.top();
            pq.pop();
            pq.push(Num(u[num.idx] * num.prime, num.idx + 1, num.prime));
        }
    }
    return u[n - 1];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

