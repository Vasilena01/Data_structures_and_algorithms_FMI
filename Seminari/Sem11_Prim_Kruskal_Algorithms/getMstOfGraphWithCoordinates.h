#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

/*First solution - Prims alg - almost works
struct Edge {
    pair<int, int> from, to;
    int weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& pair) const {
        return hash<T1>()(pair.first) ^ (hash<T2>()(pair.second) << 1);
    }
};
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    unordered_set<pair<int, int>, PairHash> visited;
    priority_queue<Edge> pq;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int, int> from = { points[i][0], points[i][1] };
            pair<int, int> to = { points[j][0], points[j][1] };
            int weight =
                abs(from.first - to.first) + abs(from.second - to.second);
            pq.push({ from, to, weight });
        }
    }

    int mstWeight = 0;
    int edgesCount = 0;
    while (!pq.empty() && edgesCount < n - 1) {
        auto curr = pq.top();
        pq.pop();

        if (visited.count(curr.to) && visited.count(curr.from))
            continue;

        mstWeight += curr.weight;
        edgesCount++;

        if (!visited.count(curr.from))
            visited.insert(curr.from);
        if (!visited.count(curr.to))
            visited.insert(curr.to);
    }

    return edgesCount == n - 1 ? mstWeight : -1;
}*/

/*Second solution - Kruskal alg*/
struct Edge {
    int from, to, weight;
    bool operator<(const Edge& other) const {
        if (weight == other.weight) {
            return (from + to + weight) < (other.from + other.to + other.weight);
        }
        return weight < other.weight;
    }
};

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false; // x and y are already in the same component
        }

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<Edge> edges;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int weight = abs(points[i][0] - points[j][0]) +
                abs(points[i][1] - points[j][1]);
            edges.push_back({ i, j, weight });
        }
    }

    sort(edges.begin(), edges.end());
    int mstWeight = 0;
    int edgesCount = 0;

    UnionFind uf(n);
    
    for (auto edge : edges)
    {
        if (uf.unite(edge.from, edge.to))
        {
            mstWeight += edge.weight;
            edgesCount++;

            if (edgesCount == n - 1)
                break;
        }
    }

    if (edgesCount != n - 1)
        return -1;
    return mstWeight;
}