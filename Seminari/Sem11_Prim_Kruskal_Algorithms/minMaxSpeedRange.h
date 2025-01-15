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
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }
};

struct UnionFind {
    vector<int> parent, rank;
    int components;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        components = n;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

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

        components--;
        return true;
    }
};

pair<int, int> findOptimalSpeed(int v, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());
    int minRange = INT_MAX;
    pair<int, int> res = {0, 0};

    for (int i = 0; i < edges.size(); i++)
    {
        UnionFind uf(v);
        int maxVal = edges[i].weight;

        for (int j = i; j < edges.size(); j++)
        {
            if (uf.unite(edges[j].from, edges[j].to))
                maxVal = edges[j].weight;

            if (uf.components == 1)
            {
                int range = maxVal - edges[i].weight;
                if (range < minRange || (range == minRange && (edges[i].weight < res.first)))
                {
                    minRange = range;
                    res = { edges[i].weight, maxVal };
                }
                break;
            }
        }
    }
    return res;
}

void input()
{
    int v, e;
    cin >> v >> e;
    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        int f, t, c;
        cin >> f >> t >> c;
        f--;
        t--;
        edges.push_back({ f, t, c });
    }

    pair<int, int> path = findOptimalSpeed(v, edges);
    cout << path.first << " " << path.second;
}