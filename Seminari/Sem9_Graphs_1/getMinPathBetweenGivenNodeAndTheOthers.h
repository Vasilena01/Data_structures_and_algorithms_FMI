#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int numVerticies;
    vector<int>* adjList;
public:
    Graph(int v) : numVerticies(v), adjList(new vector<int>[v]) {};

    void add(int v, int w)
    {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    vector<int> adj(int v) {
        return adjList[v];
    }
};

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    Graph g(n);
    for (auto it : edges)
    {
        int a = it[0] - 1;
        int b = it[1] - 1;
        g.add(a, b);
    }

    vector<int> res(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;

    visited[s - 1] = true;
    q.push(s - 1);
    res[s - 1] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : g.adj(curr))
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                res[neighbor] = res[curr] + 6;
                q.push(neighbor);
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (i != s - 1) {
            result.push_back(res[i]);
        }
    }
    return result;
}