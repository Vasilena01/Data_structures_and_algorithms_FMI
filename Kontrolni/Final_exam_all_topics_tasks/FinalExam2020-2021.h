#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/*T1 - get nums in arr1 lower than num in arr2*/
void input1() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);

    for (int i = 0; i < n; i++)
        cin >> nums1[i];

    for (int i = 0; i < m; i++)
        cin >> nums2[i];

    sort(nums1.begin(), nums1.end());
    unordered_map<int, int> numsBefore;
    numsBefore[nums1[0]] = 0;
    for (int i = 1; i < nums1.size(); i++)
        numsBefore[nums1[i]] = numsBefore[nums1[i - 1]] + 1;

    for (int num : nums2)
    {
        auto it = lower_bound(nums1.begin(), nums1.end(), num);
        int target = *it;

        cout << numsBefore[target] << " ";
    }
}

/*T6 - Count of verticies weights to remove to not form a cycle*/
struct Edge
{
    int from, to, weight;
    bool operator<(const Edge& other) const
    {
        return weight > other.weight;
    }
};
struct UnionFind
{
    vector<int> parent;
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void yunion(int x, int y)
    {
        parent[find(y)] = find(x);
    }
};
int kruskal(int v, vector<Edge>& edges)
{
    UnionFind uf(v);
    int sum = 0;
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (uf.find(edges[i].from) != uf.find(edges[i].to))
        {
            uf.yunion(edges[i].from, edges[i].to);
            sum += edges[i].weight;
        }
    }

    return sum;
}
void input6() {
    int v, e;
    cin >> v >> e;
    vector<Edge> edges;
    int total = 0;
    for (int i = 0; i < e; i++)
    {
        int f, s, c;
        cin >> f >> s >> c;
        edges.push_back({ f, s, c });
        edges.push_back({ s, f, c });
        total += c;
    }

    sort(edges.begin(), edges.end());
    int sum = kruskal(v + 1, edges);
    cout << total - sum;
}