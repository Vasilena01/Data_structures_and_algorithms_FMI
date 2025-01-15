#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

struct Edge {
	int to;
	int weight;
};

struct Node {
	int index;
	int cost;

	bool operator<(const Node& rhs) const {
		return cost > rhs.cost;
	}
};

int dijkstra(int start, int V, unordered_map<int, vector<Edge>>& graph, vector<int>& times, int end)
{
	vector<int> distances(V, INT_MAX);
	priority_queue<Node> pq;
	distances[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		if (curr.index == end)
			return distances[curr.index];

		if (curr.cost > distances[curr.index])
			continue;

		for (const auto& edge : graph[curr.index])
		{
			int needTimeToWait = curr.cost % times[curr.index];
			int newTime = curr.cost + edge.weight;
			if (needTimeToWait != 0)
				newTime += (times[curr.index] - needTimeToWait);

			if (newTime < distances[edge.to])
			{
				distances[edge.to] = newTime;
				pq.push({ edge.to, newTime });
			}
		}
	}

	return -1;
}

void input()
{
	int V, E, s, e;
	cin >> V >> E >> s >> e;
	vector<int> times(V);
	unordered_map<int, vector<Edge>> graph;
	for (int i = 0; i < V; i++)
	{
		int time;
		cin >> time;
		times[i] = time;
	}

	for (int i = 0; i < E; i++)
	{
		int first, second, c;
		cin >> first >> second >> c;
		graph[first].push_back({ second, c });
	}

	cout << dijkstra(s, V, graph, times, e);
}