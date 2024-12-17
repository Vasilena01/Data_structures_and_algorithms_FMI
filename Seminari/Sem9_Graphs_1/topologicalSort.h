#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void topologicalSort(unordered_map<int, unordered_set<int>>& graph, 
    unordered_set<int>& visited, unordered_set<int>& inProgress, 
    vector<int>& res, int curr, bool& hasCycle)
{
    if (hasCycle)
        return;

    visited.insert(curr);
    inProgress.insert(curr);

    for (int neighbor : graph[curr])
    {
        if (inProgress.count(neighbor))
        {
            hasCycle = true;
            return;
        }
        if (!visited.count(neighbor))
            topologicalSort(graph, visited, inProgress, res,
                neighbor, hasCycle);
    }
    inProgress.erase(curr);
    res.push_back(curr);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    vector<int> res;
    if (numCourses != 0 && prerequisites.empty())
    {
        for (int i = 0; i < numCourses; i++)
            res.push_back(i);
        return res;
    }

    unordered_map<int, unordered_set<int>> graph;

    for (auto it : prerequisites)
        graph[it[1]].insert(it[0]);

    unordered_set<int> visited;
    unordered_set<int> inProgress;
    bool hasCycle = false;

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited.count(i))
        {
            topologicalSort(graph, visited, inProgress, res,
                i, hasCycle);
            if (hasCycle)
                return {};
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}