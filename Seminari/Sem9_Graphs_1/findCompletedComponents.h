#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

void dfs(int curr, unordered_map<int, unordered_set<int>>& graph,
    unordered_set<int>& visited, stack<int>& currVisited)
{
    visited.insert(curr);
    currVisited.push(curr);
    for (int neighbor : graph[curr])
    {
        if (!visited.count(neighbor))
            dfs(neighbor, graph, visited, currVisited);
    }
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].insert(edges[i][1]);
        graph[edges[i][1]].insert(edges[i][0]);
    }
    unordered_set<int> visited;
    stack<int> currVisited;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited.count(i))
        {
            bool isComplete = true;
            dfs(i, graph, visited, currVisited);
            int size = currVisited.size();
            while (!currVisited.empty())
            {
                int node = currVisited.top();
                currVisited.pop();
                if (graph[node].size() != size - 1)
                    isComplete = false;
            }
            if (isComplete)
                count++;
        }
    }
    return count;
}