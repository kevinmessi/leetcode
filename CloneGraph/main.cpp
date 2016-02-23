#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

#include "../toolkit/data_structure.h"

using namespace std;

UndirectedGraphNode *cloneGraph1(UndirectedGraphNode *node)
{
    if (node == NULL) return NULL;
    UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    queue<UndirectedGraphNode*> nodes;
    nodes.push(node);
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
    visited[node] = new_node;
    while (!nodes.empty())
    {
        UndirectedGraphNode *p = nodes.front();
        nodes.pop();
        for (UndirectedGraphNode *n : p->neighbors)
        {
            if (visited.find(n) == visited.end())
            {
                visited[n] = new UndirectedGraphNode(n->label);
                nodes.push(n);
            }
            visited[p]->neighbors.push_back(visited[n]);
        }
    }
    return new_node;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &visited)
{
    if (node == NULL) return NULL;
    if (visited.find(node) == visited.end())
    {
        visited[node] = new UndirectedGraphNode(node->label);
        for (UndirectedGraphNode *n : node->neighbors)
        {
            visited[node]->neighbors.push_back(cloneGraph(n, visited));
        }
    }
    return visited[node];
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
    return cloneGraph(node, visited);
}

int main()
{
    return 0;
}

