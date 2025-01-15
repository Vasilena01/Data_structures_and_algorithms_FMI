#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int index;
    int cost;

    bool operator>(const Node& rhs) const {
        return cost < rhs.cost;
    }
};

int dijkstra(int start, int V, int end, unordered_map<int, vector<Edge>>& graph)
{
    vector<int> distances(V + 1, INT_MIN);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    distances[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if (curr.cost < distances[curr.index])
            continue;
        
        for (auto edge : graph[curr.index])
        {
            int newCost = edge.weight + curr.cost;
            if (newCost > distances[edge.to])
            {
                distances[edge.to] = newCost;
                pq.push({ edge.to, newCost });
            }
        }
    }
    if (distances[end] != INT_MIN)
        return distances[end];
    else
        return -1;
}

void input()
{
    int V, E, s, e;
    cin >> V >> E >> s >> e;
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < E; i++)
    {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        graph[v1].push_back({ v2, c });
    }

    cout << dijkstra(s, V, e, graph);
}