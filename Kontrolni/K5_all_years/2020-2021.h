#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

/*Task 1*/
void dfs(int curr, unordered_map<int, unordered_set<int>>& graph,
    unordered_set<int>& visited)
{
    visited.insert(curr);

    for (int neighbor : graph[curr])
    {
        if (!visited.count(neighbor))
            dfs(neighbor, graph, visited);
    }
}
void getComponents()
{
    size_t nodesCount, edgesCount;
    std::cin >> nodesCount >> edgesCount;

    unordered_map<int, unordered_set<int>> graph(nodesCount);

    for (size_t i = 0; i < edgesCount; i++) {
        size_t first, second;
        cin >> first >> second;
        graph[first].insert(second);
        graph[second].insert(first);
    }

    unordered_set<int> visited;
    int count = 0;
    for (int i = 0; i < nodesCount; i++)
    {
        if (graph.count(i) == 0 && graph[i].size() == 0)
            continue;
        if (!visited.count(i))
        {
            dfs(i, graph, visited);
            count++;
        }
    }
    cout << count;
}

/*Task 2*/
void isGivenPathInGraph()
{
    int m;
    cin >> m;
    unordered_map<int, unordered_set<int>> graph(m);
    for (int i = 0; i < m; i++)
    {
        int vCount;
        cin >> vCount;
        for (int j = 0; j < vCount; j++)
        {
            int v;
            cin >> v;
            graph[i].insert(v);
            graph[v].insert(i);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        vector<int> path;
        int vCount;
        cin >> vCount;
        for (int j = 0; j < vCount; j++)
        {
            int v;
            cin >> v;
            path.push_back(v);
        }

        bool isFullPathInComponent = true;
        for (int j = 1; j < vCount; j++)
        {
            int from = path[j - 1];
            int to = path[j];
            if (!graph[from].count(to))
            {
                isFullPathInComponent = false;
                break;
            }
        }

        cout << isFullPathInComponent << " ";
    }
}