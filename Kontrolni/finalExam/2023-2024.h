#pragma once
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <climits>
#include <iostream>
#include <bitset>
#include <numeric>
using namespace std;

/*Task 3 - find count of components with cycles in graph*/
void dfsCycle(int curr, int parent, unordered_map<int, unordered_set<int>>& graph, vector<int>& visited, bool& hasCycle)
{
    visited[curr] = 1;
    for (int neighbor : graph[curr])
    {
        if (!visited[neighbor])
            dfsCycle(neighbor, curr, graph, visited, hasCycle);

        if (visited[neighbor] == 2)
            continue;

        if (visited[neighbor] == 1 && neighbor != parent)
        {
            hasCycle = true;
            continue;
        }
    }

    visited[curr] = 2;
}
void input3()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
        }

        vector<int> visited(n, 0);
        int cyclicCompCount = 0;
        for (int i = 0; i < n; i++)
        {
            bool hasCycle = false;
            if (!visited[i])
            {
                dfsCycle(i, -1, graph, visited, hasCycle);
                if (hasCycle)
                    cyclicCompCount++;
            }
        }
        cout << cyclicCompCount << endl;
    }
}

/*Task 4 - Get mstWeight of trees with vertex count % k == 0*/
struct Edge
{
  int from, to, cost;
    bool operator<(const Edge& other) const
    {
        return cost > other.cost;
    }
};
int prim(int n, int start, unordered_map<int, vector<Edge>>& graph, 
    unordered_set<int>& visited, int& count)
{
    priority_queue<Edge> pq;
    pq.push({ start, start, 0 });
    int mstWeight = 0;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if (visited.count(curr.to))
            continue;

        visited.insert(curr.to);
        mstWeight += curr.cost;
        count++;
        for (auto edge : graph[curr.to])
        {
            if (visited.count(edge.to))
                continue;
            pq.push(edge);
        }
    }

    return mstWeight;
}
void input4()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v, e, k;
        cin >> v >> e >> k;
        unordered_map<int, vector<Edge>> graph;
        for (int j = 0; j < e; j++)
        {
            int x, y, c;
            cin >> x >> y >> c;
            graph[x].push_back({ x, y, c });
            graph[y].push_back({ y, x, c });
        }

        int res = 0;
        unordered_set<int> visited(v);
        for (int i = 0; i < v; i++)
        {
            if (!visited.count(i))
            {
                int verticiesCount = 0;
                int currRes = prim(v, i, graph, visited, verticiesCount);
                if (verticiesCount % k == 0)
                    res += currRes;
            }
        }
        
        cout << res << endl;
    }
}