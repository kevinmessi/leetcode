#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> findItinerary1(vector<pair<string, string>> &tickets)
{
    vector<string> itinerary;
    unordered_map<string, multiset<string>> graph;
    for (auto &ticket : tickets)
        graph[ticket.first].insert(ticket.second);
    stack<string> airports;
    airports.push("JFK");
    while (!airports.empty())
    {
        string from = airports.top();
        while (!graph[from].empty())
        {
            string to = *graph[from].begin();
            airports.push(to);
            graph[from].erase(graph[from].begin());
            from = to;
        }
        itinerary.push_back(from);
        airports.pop();
    }
    reverse(itinerary.begin(), itinerary.end());
    return itinerary;
}

void findItinerary(string from, unordered_map<string, multiset<string>> &graph, vector<string> &itinerary)
{
    while (!graph[from].empty())
    {
        string to = *graph[from].begin();
        graph[from].erase(graph[from].begin());
        findItinerary(to, graph, itinerary);
    }
    itinerary.push_back(from);
}

vector<string> findItinerary(vector<pair<string, string>> &tickets)
{
    vector<string> itinerary;
    unordered_map<string, multiset<string>> graph;
    for (auto &ticket : tickets)
        graph[ticket.first].insert(ticket.second);
    findItinerary("JFK", graph, itinerary);
    reverse(itinerary.begin(), itinerary.end());
    return itinerary;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
