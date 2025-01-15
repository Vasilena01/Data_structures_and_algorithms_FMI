#pragma once
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to;
    double weight;
};

struct Node {
    int index;
    double probability;

    bool operator>(const Node& rhs) const {
        return probability < rhs.probability;
    }
};
double dijkstra(int start, int end,
    unordered_map<int, vector<Edge>>& graph, int n) {
    vector<double> probabilities(n, INT_MIN);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    probabilities[start] = 0;
    pq.push({ start, 1 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.index == end)
            return curr.probability;

        if (curr.probability < probabilities[curr.index])
            continue;

        for (auto neighbor : graph[curr.index]) {
            double newProb = curr.probability * neighbor.weight;

            if (newProb > probabilities[neighbor.to]) {
                probabilities[neighbor.to] = newProb;
                pq.push({ neighbor.to, newProb });
            }
        }
    }

    return 0.0;
}
double maxProbability(int n, vector<vector<int>>& edges,
    vector<double>& succProb, int start_node,
    int end_node) {
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < edges.size(); i++) {
        vector<int>& curr = edges[i];
        double probability = succProb[i];
        graph[curr[0]].push_back({ curr[1], probability });
        graph[curr[1]].push_back({ curr[0], probability });
    }

    return dijkstra(start_node, end_node, graph, n);
}