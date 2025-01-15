#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

const int MOD = 1e9 + 7;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int index;
    int distance;

    bool operator<(const Node& rhs) const {
        return distance > rhs.distance; // Min-heap
    }
};

pair<int, int> dijkstra(int start, int end, unordered_map<int, vector<Edge>>& graph, int v) {
    vector<int> distances(v + 1, INT_MAX);
    vector<int> pathCount(v + 1, 0); // Number of ways to reach each node

    distances[start] = 0;
    pathCount[start] = 1;

    priority_queue<Node> pq;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.distance > distances[curr.index]) {
            continue;
        }

        for (auto& neighbor : graph[curr.index]) {
            int newDist = curr.distance + neighbor.weight;

            if (newDist < distances[neighbor.to]) {
                distances[neighbor.to] = newDist;
                pathCount[neighbor.to] = pathCount[curr.index];
                pq.push({ neighbor.to, newDist });
            }
            else if (newDist == distances[neighbor.to]) {
                pathCount[neighbor.to] = (pathCount[neighbor.to] + pathCount[curr.index]) % MOD;
            }
        }
    }

    int minDistance = distances[end];
    int ways = pathCount[end];

    if (minDistance == INT_MAX) {
        return { -1, 0 }; // No path to the destination
    }

    return { minDistance, ways };
}

void input() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<Edge>> graph;

    for (int i = 0; i < e; i++) {
        int f, s, c;
        cin >> f >> s >> c;
        graph[f].push_back({ s, c }); // Directed graph
    }

    int start = 1;
    int end = v;
    auto result = dijkstra(start, end, graph, v);

    cout << result.first << " " << result.second << endl;
}