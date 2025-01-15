#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

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

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    vector<Edge> edges;
    for (int i = 0; i < g_from.size(); i++)
    {
        int st = g_from[i];
        int end = g_to[i];
        int weight = g_weight[i];
        edges.push_back({ st, end, weight });
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(g_nodes);
    int mstWeight = 0;
    int edgeCount = 0;

    for (auto edge : edges)
    {
        if (uf.unite(edge.from, edge.to))
        {
            mstWeight += edge.weight;
            edgeCount++;

            if (edgeCount == g_nodes - 1)
                break;
        }
    }

    if (edgeCount != g_nodes - 1)
        return -1;
    return mstWeight;
}