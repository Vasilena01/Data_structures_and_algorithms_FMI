#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;
/*Task 1 - partly*/

void dfsComponentsCount(int curr, unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited)
{
    visited[curr] = true;
    for (int neighbor : graph[curr])
    {
        if (!visited[neighbor])
            dfsComponentsCount(neighbor, graph, visited);
    }
}

bool dfsCycle(int curr, unordered_map<int, unordered_set<int>>& graph, vector<int>& state) {
    state[curr] = 0;
    for (int neighbor : graph[curr]) {
        if (state[neighbor] == 0) {
            return true;
        }
        if (state[neighbor] == -1 && dfsCycle(neighbor, graph, state)) {
            return true;
        }
    }
    state[curr] = 1;
    return false;
}

void getInput()
{
    int n;
    cin >> n;

    unordered_map<int, unordered_set<int>> graph;
    int s, e;
    while (cin >> s >> e)
    {
        graph[s - 1].insert(e - 1);
        graph[e - 1].insert(s - 1);
        vector<bool> visited(n, false);
        vector<int> states(n, -1);
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                dfsComponentsCount(j, graph, visited);
                count++;
            }
        }
        bool hasCycle = false;
        for (int i = 0; i < n; i++) {
            if (states[i] == -1 && dfsCycle(i, graph, states)) {
                hasCycle = true;
                break;
            }
        }
        cout << count << (hasCycle ? " CYCLE FORMED!" : "") << endl;
    }
}

/*Task 2*/
struct Edge
{
	int to;
	int weight;
};

struct Node
{
	int index;
	int cost;

	bool operator<(const Node& rhs) const
	{
		return cost > rhs.cost;

	}
};

void dijkstra(int V, unordered_map<int, vector<Edge>>& graph) {
    vector<pair<int, int>> distances(V + 1, { INT_MAX, 0 });
    priority_queue<Node> pq;
    distances[1] = { 0, 1 }; // Start at node 1 with 1 way to reach it
    pq.push({ 1, 0 });

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        if (curr.cost > distances[curr.index].first)
            continue;

        for (auto edge : graph[curr.index]) {
            int newCost = curr.cost + edge.weight;
            if (newCost < distances[edge.to].first) {
                distances[edge.to].first = newCost;
                distances[edge.to].second = distances[curr.index].second;
                pq.push({ edge.to, newCost });
            }
            else if (newCost == distances[edge.to].first) {
                distances[edge.to].second =
                    (distances[edge.to].second + distances[curr.index].second) % 1000000007;
            }
        }
    }

    if (distances[V].first != INT_MAX) {
        cout << distances[V].first << " " << distances[V].second;
    }
    else {
        cout << -1 << " " << 0;
    }
}

void input()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, vector<Edge>> graph;
	for (int i = 0; i < e; i++)
	{
		int f, s, c;
		cin >> f >> s >> c;
		graph[f].push_back({ s, c });
	}

	dijkstra(v, graph);
}