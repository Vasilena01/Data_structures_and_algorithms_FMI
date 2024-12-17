#pragma once
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(int curr, unordered_map<int, unordered_set<int>>& graph, vector<int>& path, vector<vector<int>>& res, int& end)
{
    path.push_back(curr);

    if (curr == end)
        res.push_back(path);
    else
    {
        for (int neighbor : graph[curr])
            dfs(neighbor, graph, path, res, end);
    }

    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& my_graph) {
    unordered_map<int, unordered_set<int>> graph;
    vector<int> path;
    vector<vector<int>> res;
    int start = 0;
    int end = my_graph.size() - 1;

    for (int i = 0; i < my_graph.size(); i++)
    {
        for (int v : my_graph[i])
            graph[i].insert(v);
    }

    dfs(start, graph, path, res, end);
    return res;
}