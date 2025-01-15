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
        return cost > rhs.cost; // Min-heap based on cost
    }
};

vector<int> dijkstra(int start, int V, unordered_map<int, vector<Edge>>& graph) {
    vector<int> distances(V, INT_MAX);
    priority_queue<Node> pq;
    distances[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.cost > distances[curr.index]) continue;

        for (auto neighbor : graph[curr.index]) {
            int newWeight = neighbor.weight + curr.cost;
            if (newWeight < distances[neighbor.to]) {
                distances[neighbor.to] = newWeight;
                pq.push({ neighbor.to, newWeight });
            }
        }
    }
    return distances;
}

int findMinValue(vector<int>& distances, unordered_set<int>& T) {
    int minDistance = INT_MAX;
    for (int node : T) {
        minDistance = min(minDistance, distances[node]);
    }
    return minDistance;
}

void input() {
    unordered_map<int, vector<Edge>> graph;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        graph[x].push_back({ y, c });
        graph[y].push_back({ x, c });
    }

    unordered_set<int> T;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int el;
        cin >> el;
        T.insert(el);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int node;
        cin >> node;

        vector<int> distances = dijkstra(node, n, graph);
        cout << findMinValue(distances, T) << endl;
    }
}