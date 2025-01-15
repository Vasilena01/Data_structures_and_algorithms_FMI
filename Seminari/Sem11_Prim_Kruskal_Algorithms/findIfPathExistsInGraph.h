#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX == parentY)
            return;

        if (rank[parentX] > rank[parentY])
            parent[parentY] = parentX;
        else if (rank[parentY] > rank[parentX])
            parent[parentX] = parentY;
        else
        {
            parent[parentY] = parentX;
            rank[parentX]++;
        }
    }
};
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    UnionFind uf(n);
    for (auto edge : edges)
    {
        uf.unite(edge[0], edge[1]);
    }

    return uf.find(source) == uf.find(destination);
}