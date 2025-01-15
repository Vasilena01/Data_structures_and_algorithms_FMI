#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
#include <bitset>
using namespace std;

/*First approach not very correct for all testCases - with prim*/
struct Edge {
    int from, to, weight;
    bool operator<(const Edge& other) const
    {
        return weight > other.weight;
    }
};

int prim(int v, int start, int end, unordered_map<int, vector<Edge>>& graph)
{
    priority_queue<Edge> pq;
    unordered_set<int> visited;
    pq.push({ start, start, 0 });

    int mstWeight = 0;

    while (!pq.empty() && visited.size() < v)
    {
        auto curr = pq.top();
        pq.pop();

        if (visited.count(end))
            return mstWeight;

        if (visited.count(curr.to))
            continue;

        visited.insert(curr.to);
        mstWeight += curr.weight;
        for (auto edge : graph[curr.to])
        {
            if (visited.count(edge.to))
                continue;
            pq.push(edge);
        }
    }

    return mstWeight;
}

void input()
{
    int v, e;
    cin >> v >> e;

    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < e; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        c = pow(2, c);
        graph[x].push_back({ x, y, c });
        graph[y].push_back({ y, x, c });
    }

    int sum = 0;
    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            sum += prim(v, i, j, graph);
            cout << prim(v, i, j, graph) << endl;
        }
    }
    cout << sum << endl;
    bitset<8> binary(sum);
    cout << binary.to_string();
}

/*Second approach with dijkstra*/
struct Edge2
{
    int to, weight;
};

struct Node
{
    int index, cost;
    bool operator<(const Node& other) const
    {
        return cost > other.cost;
    }
};
int dijkstra(int n, unordered_map<int, vector<Edge2>>& graph, int st, int end)
{
    priority_queue<Node> pq;
    vector<int> distances(n, INT_MAX);
    pq.push({ st, 0 });
    distances[st] = 0;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if (curr.index == end)
            return curr.cost;

        if (curr.cost > distances[curr.index])
            continue;

        for (auto edge : graph[curr.index])
        {
            int newCost = edge.weight + curr.cost;
            if (newCost < distances[edge.to])
            {
                distances[edge.to] = newCost;
                pq.push({ edge.to, newCost });
            }
        }
    }

    if (distances[end] != INT_MAX)
        return distances[end];
    return -1;
}

string roadsInHackerland(int n, vector<vector<int>> roads) {
    unordered_map<int, vector<Edge2>> graph;
    for (size_t i = 0; i < roads.size(); i++)
    {
        int weight = pow(2, roads[i][2]);
        graph[roads[i][0]].push_back({ roads[i][1], weight });
        graph[roads[i][1]].push_back({ roads[i][0], weight });
    }

    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum += dijkstra(n, graph, i, j);
        }
    }
    bitset<8> binary(sum);
    cout << sum;
    return binary.to_string();
}

void input2()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> roads;
    for (int i = 0; i < e; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        roads.push_back({ x, y, c });
    }
    roadsInHackerland(v, roads);
}