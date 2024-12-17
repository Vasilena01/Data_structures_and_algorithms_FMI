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
    }

    vector<int> adj(int v) {
        return adjList[v];
    }
};

bool dfsCycle(Graph& g, int v, vector<bool>& visited, vector<bool>& recursionStack)
{
    visited[v] = true;
    recursionStack[v] = true;

    for (int neighbor : g.adj(v))
    {
        if (!visited[neighbor])
        {
            if (dfsCycle(g, neighbor, visited, recursionStack))
                return true;
        }
        else if (recursionStack[neighbor])
        {
            return true;
        }
    }
    recursionStack[v] = false;
    return false;
}

int getInput() {
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
            g.add(x - 1, y - 1);
        }
        vector<bool> visited(v, false);
        vector<bool> recursionStack(v, false);
        bool hasCycle = false;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfsCycle(g, i, visited, recursionStack))
                {
                    hasCycle = true;
                    break;
                }
            }
        }
        hasCycle == true ? cout << "true" << " " : cout << "false" << " ";
    }
    return 0;
}