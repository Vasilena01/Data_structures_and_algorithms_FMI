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

/*To solve:
    - exam 5 - 2018-2019 task2
*/

/*T1 - Find shortest paths from startNode to all other nodes in graph*/
struct Edge
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
void dijkstra(int start, unordered_map<int, vector<Edge>>& graph, vector<int>& distances)
{
    priority_queue<Node> pq;
    pq.push({ start, 0 });

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        if (curr.cost > distances[curr.index])
            continue;

        for (auto edge : graph[curr.index])
        {
            int newWeight = edge.weight + curr.cost;
            if (newWeight < distances[edge.to])
            {
                distances[edge.to] = newWeight;
                pq.push({ edge.to, newWeight });
            }
        }
    }
}
void input1() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < e; i++)
    {
        int f, s, c;
        cin >> f >> s >> c;
        graph[f].push_back({ s, c });
        graph[s].push_back({ f, c });
    }

    int start;
    cin >> start;
    vector<int> distances(v + 1, INT_MAX);
    distances[start] = 0;
    dijkstra(start, graph, distances);

    for (size_t i = 1; i < distances.size(); i++)
    {
        if (i != start) {
            if (distances[i] != INT_MAX) {
                cout << distances[i] << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
    }
}

/*T2 - find shortes path weight to end node and the ways to reach it*/
struct Edge
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
void dijkstra(int start, int end, int v, unordered_map<int, vector<Edge>>& graph)
{
    priority_queue<Node> pq;
    vector<int> distances(v, INT_MAX);
    vector<int> ways(v, 0);
    pq.push({ start, 0 });
    distances[start] = 0;
    ways[start] = 1;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if (curr.cost > distances[curr.index])
            continue;

        for (auto edge : graph[curr.index])
        {
            int newWeight = (edge.weight + curr.cost);

            if (newWeight < distances[edge.to])
            {
                distances[edge.to] = newWeight;
                ways[edge.to] = ways[curr.index];
                pq.push({ edge.to, newWeight });
            }
            else if (newWeight == distances[edge.to])
            {
                ways[edge.to] = (ways[edge.to] + ways[curr.index]) % 1000000007;
            }
        }
    }

    if (distances[end] == INT_MAX)
        cout << -1 << " " << 0;
    else
        cout << distances[end] << " " << ways[end];
}
void input2() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < e; i++)
    {
        int f, s, c;
        cin >> f >> s >> c;
        graph[f - 1].push_back({ s - 1, c });
    }

    dijkstra(0, v - 1, v, graph);
}