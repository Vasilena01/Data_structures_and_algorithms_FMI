#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(unordered_map<int, unordered_set<int>>& graph,
    int start, unordered_set<int>& visited)
{
    visited.insert(start);
    for (int neighbor : graph[start])
    {
        if (!visited.count(neighbor))
        {
            dfs(graph, neighbor, visited);
        }
    }
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int, unordered_set<int>> graph;
    for (auto it : edges)
    {
        graph[it[0]].insert(it[1]);
        graph[it[1]].insert(it[0]);
    }
    unordered_set<int> visited;
    dfs(graph, source, visited);
    if (visited.count(destination))
        return true;
    else
        return false;
}