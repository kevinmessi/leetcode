#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent1(vector<int> &nums, int k)
{
    unordered_map<int, int> counter;
    for (int n : nums)
        ++counter[n];
    priority_queue<pair<int, int>> pq;
    auto iter = counter.begin();
    for (int i = counter.size(); i > k && iter != counter.end(); ++iter, --i)
        pq.emplace(iter->second, iter->first);
    vector<int> top_k;
    for (; iter != counter.end(); ++iter)
    {
        pq.emplace(iter->second, iter->first);
        top_k.push_back(pq.top().second);
        pq.pop();
    }
    return top_k;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> counter;
    for (int n : nums)
        ++counter[n];
    vector<vector<int>> buckets(nums.size() + 1);
    for (const auto &item : counter)
        buckets[item.second].push_back(item.first);
    vector<int> top_k;
    for (int i = buckets.size() - 1; i >= 0 && k != top_k.size(); --i)
    {
        for (int n : buckets[i])
        {
            top_k.push_back(n);
            if (k == top_k.size()) return top_k;
        }
    }
    return top_k;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
