#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

int dfs(int curr, unordered_map<int, unordered_set<size_t>>& graph, 
    unordered_set<size_t>& visited, int& res)
{
    if (graph[curr].size() == 0)
        return 1;

    visited.insert(curr);
    int childrenCount = 1;
    for (int neighbor : graph[curr])
    {
        if (!visited.count(neighbor))
            childrenCount += dfs(neighbor, graph, visited, res);
    }

    if (childrenCount % 2 == 0)
    {
        res++;
        return 0;
    }
    return childrenCount;
}
void removeVerticies()
{
    size_t nodesCount, edgesCount;
    std::cin >> nodesCount >> edgesCount;

    unordered_map<int, unordered_set<size_t>> graph(nodesCount + 1);

    for (size_t i = 0; i < edgesCount; i++) {
        size_t first, second;
        cin >> first >> second;
        graph[first].insert(second);
        graph[second].insert(first);
    }

    unordered_set<size_t> visited;
    int result = 0;
    dfs(1, graph, visited, result);

    std::cout << result - 1;
}

/*Pq - time managing*/
void maxPeopleTrainingTogether()
{
    int n;
    cin >> n;
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        maxHeap.push({ f, s });
    }

    int count = 1;
    while (maxHeap.size())
    {
        int start = maxHeap.top().first;
        int end = maxHeap.top().second;
        maxHeap.pop();

        while (maxHeap.size() && maxHeap.top().second > start)
        {
            count++;
            maxHeap.pop();
        }
    }
    cout << count;
}