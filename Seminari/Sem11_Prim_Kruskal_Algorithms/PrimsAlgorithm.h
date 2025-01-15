#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

/*First solution*/
int prims(int n, vector<vector<int>> edges, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // to, weight
    unordered_set<int> visited;
    pq.push({ start, 0 });
    int mstWeight = 0;

    while (!pq.empty() && visited.size() < n)
    {
        auto curr = pq.top();
        pq.pop();

        if (visited.count(curr.first))
            continue;

        visited.insert(curr.first);
        mstWeight += curr.second;
        for (auto neighbor : edges)
        {
            if (neighbor[0] == curr.first)
            {
                if (visited.count(neighbor[1]))
                    continue;

                pq.push({ neighbor[1], neighbor[2] });
            }
        }
    }
    return mstWeight;
}

/*Second solution*/
int prims2(int n, vector<vector<int>> edges, int start) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (auto& edge : edges) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
        graph[edge[1]].emplace_back(edge[0], edge[2]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    unordered_set<int> visited;
    int mstWeight = 0;
    pq.push({ 0, start });

    while (!pq.empty() && visited.size() < n) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited.count(node))
            continue;

        mstWeight += weight;
        visited.insert(node);

        for (auto& neighbor : graph[node]) {
            if (!visited.count(neighbor.first)) {
                pq.push({ neighbor.second, neighbor.first });
            }
        }
    }

    if (visited.size() != n) {
        return -1; // Graph is not connected
    }

    return mstWeight;
}
