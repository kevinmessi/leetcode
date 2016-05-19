#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
{
    if (n == 1) return{ 0 };
    vector<unordered_set<int>> graph(n);
    for (auto &edge : edges)
    {
        graph[edge.first].insert(edge.second);
        graph[edge.second].insert(edge.first);
    }
    vector<int> leaves;
    for (int i = 0; i < n; ++i)
    {
        if (graph[i].size() == 1)
            leaves.push_back(i);
    }
    while (n > 2)
    {
        n -= leaves.size();
        vector<int> new_leaves;
        for (int i : leaves)
        {
            int j = *graph[i].begin();
            graph[j].erase(i);
            if (graph[j].size() == 1)
                new_leaves.push_back(j);
        }
        leaves = move(new_leaves);
    }
    return leaves;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
