#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool find_order_dfs(vector<vector<int>> &graph, int vertex, vector<int> &path, vector<int> &visited, int &pos, vector<int> &order)
{
    if (visited[vertex]) return false;
    visited[vertex] = 1, path[vertex] = 1;
    for (int n : graph[vertex])
    {
        if (path[n] || find_order_dfs(graph, n, path, visited, pos, order))
            return true;
    }
    order[pos] = vertex;
    --pos;
    path[vertex] = 0;
    return false;
}

vector<int> findOrder1(int numCourses, vector<pair<int, int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (auto &edge : prerequisites)
        graph[edge.second].push_back(edge.first);
    vector<int> visited(numCourses, 0);
    vector<int> path(numCourses, 0);
    vector<int> order(numCourses);
    int pos = numCourses - 1;
    for (int i = 0; i < numCourses; ++i)
    {
        if (!visited[i] && find_order_dfs(graph, i, path, visited, pos, order))
            return vector<int>();
    }
    return order;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (auto &edge : prerequisites)
        graph[edge.second].push_back(edge.first);
    vector<int> indegrees(numCourses, 0);
    for (auto &neighbors : graph)
    {
        for (int n : neighbors)
            ++indegrees[n];
    }
    queue<int> vertexes;
    for (int i = 0; i < numCourses; ++i)
        if (indegrees[i] == 0) vertexes.push(i);
    vector<int> order;
    int count = 0;
    while (!vertexes.empty())
    {
        ++count;
        int j = vertexes.front();
        vertexes.pop();
        order.push_back(j);
        for (int n : graph[j])
        {
            if (--indegrees[n] == 0)
                vertexes.push(n);
        }
    }
    return count == numCourses ? order : vector<int>();
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

