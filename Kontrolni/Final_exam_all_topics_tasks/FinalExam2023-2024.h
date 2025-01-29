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

/*T1 - resolve !!!*/

/*T2 - resolve !!!*/

/*T3 - get count of components with cycle*/
void dfsCycle(int curr, int parent, unordered_map<int, unordered_set<int>>& graph, vector<int>& visited, bool& hasCycle)
{
    visited[curr] = 1;
    for (int neighbor : graph[curr])
    {
        if (!visited[neighbor])
            dfsCycle(neighbor, curr, graph, visited, hasCycle);

        if (visited[neighbor] == 2)
            continue;

        // Having the parent check because the graph is not oriented and it will 
        // detect that there is a cycle between each two nodes
        if (visited[neighbor] == 1 && parent != neighbor)
        {
            hasCycle = true;
            continue;
        }
    }

    visited[curr] = 2;
}
void input1()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v, e;
        cin >> v >> e;
        unordered_map<int, unordered_set<int>> graph;

        for (int j = 0; j < e; j++)
        {
            int f, s;
            cin >> f >> s;
            graph[f].insert(s);
            graph[s].insert(f);
        }

        vector<int> visited(v, 0);
        int count = 0;
        for (int j = 0; j < v; j++)
        {
            bool hasCycle = false;
            if (!visited[j])
            {
                dfsCycle(j, -1, graph, visited, hasCycle);
                if (hasCycle)
                    count++;
            }
        }
        cout << count << endl;
    }
}

/*T4 - get path sum of components with vcount % k == 0*/
struct Edge
{
    long long to, weight;
    bool operator<(const Edge& other) const
    {
        return weight > other.weight;
    }
};
int prim(long long start, unordered_map<long long, vector<Edge>>& graph, unordered_set<long long>& visited,
    long long& vcount)
{
    priority_queue<Edge> pq;
    pq.push({ start, 0 });
    long long mstWeight = 0;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if (visited.count(curr.to))
            continue;

        visited.insert(curr.to);
        vcount++;
        mstWeight += curr.weight;
        for (auto neighbor : graph[curr.to])
        {
            if (visited.count(neighbor.to))
                continue;
            pq.push(neighbor);
        }
    }
    return mstWeight;
}
void input2()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long v, e, k;
        cin >> v >> e >> k;
        unordered_map<long long, vector<Edge>> graph;

        for (long long i = 0; i < e; i++)
        {
            long long f, s, c;
            cin >> f >> s >> c;
            graph[f].push_back({ s, c });
            graph[s].push_back({ f, c });
        }

        unordered_set<long long> visited;
        long long resSum = 0;
        for (long long j = 0; j < v; j++)
        {
            if (!visited.count(j))
            {
                long long vcount = 0;
                long long currSum = prim(j, graph, visited, vcount);
                if (vcount % k == 0)
                    resSum += currSum;
            }
        }
        cout << resSum << endl;
    }
}

