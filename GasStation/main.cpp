#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int start = 0, gas_left = 0, gas_needed = 0;
    for (int i = 0; i < n; ++i)
    {
        gas_left += gas[i] - cost[i];
        if (gas_left < 0)
        {
            start = i + 1;
            gas_needed -= gas_left;
            gas_left = 0;
        }
    }
    return gas_left < gas_needed ? -1 : start;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

