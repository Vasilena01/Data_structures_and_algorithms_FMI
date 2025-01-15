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

    bool operator<(const Node& rhs) const {
        return cost > rhs.cost;
    }
};

vector<int> dijkstra(int start, int V,
    unordered_map<int, vector<Edge>>& graph) {
    vector<int> distances(V, INT_MAX);
    priority_queue<Node> pq;
    distances[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.cost > distances[curr.index])
            continue;

        for (auto neighbor : graph[curr.index]) {
            int newWeight = curr.cost + neighbor.weight;
            if (newWeight < distances[neighbor.to]) {
                distances[neighbor.to] = newWeight;
                pq.push({ neighbor.to, newWeight });
            }
        }
    }
    return distances;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int, vector<Edge>> graph;
    int V = n + 1;
    for (int i = 0; i < times.size(); i++) {
        vector<int>& curr = times[i];
        graph[curr[0]].push_back({ curr[1], curr[2] });
    }

    if (graph[k].size() == 0)
        return -1;

    vector<int> distances = dijkstra(k, V, graph);
    for (int i = 1; i < V; i++) {
        if (distances[i] == INT_MAX)
            return -1;
    }
    distances.erase(distances.begin());
    return *max_element(distances.begin(), distances.end());
}