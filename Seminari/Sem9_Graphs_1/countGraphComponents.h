#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
void dfsComponents(Graph g, int v, vector<bool>& visited)
{
    visited[v] = true;
    for (int num : g.adj(v))
    {
        if (!visited[num])
        {
            dfsComponents(g, num, visited);
        }
    }
}

void mainLogic() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v, e;
        cin >> v >> e;
        Graph g(v);
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            g.add(x, y);
        }

        vector<bool> visited(v, false);
        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                count++;
                dfsComponents(g, i, visited);
            }
        }
        cout << count << " ";
    }
}
