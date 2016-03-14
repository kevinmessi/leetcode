#include <iostream>
#include <vector>

using namespace std;

bool has_cycle_dfs(vector<vector<int>> &graph, int vertex, vector<int> &path, vector<int> &visited)
{
    if (visited[vertex]) return false;
    visited[vertex] = 1, path[vertex] = 1;
    for (int n : graph[vertex])
    {
        if (path[n] || has_cycle_dfs(graph, n, path, visited))
            return true;
    }
    path[vertex] = 0;
    return false;
}

bool canFinish1(int numCourses, vector<pair<int, int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (auto &edge : prerequisites)
        graph[edge.second].push_back(edge.first);
    vector<int> visited(numCourses, 0);
    vector<int> path(numCourses, 0);
    for (int i = 0; i < numCourses; ++i)
    {
        if (!visited[i] && has_cycle_dfs(graph, i, path, visited))
            return false;
    }
    return true;
}

bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
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
    for (int i = 0; i < numCourses; ++i)
    {
        int j = 0;
        while (j < numCourses && indegrees[j] != 0)
            ++j;
        if (j == numCourses) return false;
        indegrees[j] = -1;
        for (int n : graph[j])
            --indegrees[n];
    }
    return true;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

