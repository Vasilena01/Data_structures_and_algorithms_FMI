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
	int duration;
};

struct Node {
	int index;
	int time;

	bool operator<(const Node& rhs) const {
		return time > rhs.time;
	}
};

bool dijkstra(int start, int V, unordered_map<int, vector<Edge>>& graph, int maxtime, int maxWeight)
{
	vector<int> times(V + 1, INT_MAX);
	priority_queue<Node> pq;
	times[start] = 0;
	pq.push({ start, 0});

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		if (curr.index == V && curr.time <= maxtime)
			return true;

		if (curr.time > times[curr.index])
			continue;

		for (auto edge : graph[curr.index])
		{
			if (edge.weight > maxWeight)
				continue;

			int newTime = edge.duration + curr.time;
			if (newTime <= maxtime && newTime < times[edge.to])
			{
				times[edge.to] = newTime;
				pq.push({ edge.to, newTime });
			}
		}
	}

	return false;
}

int binarySearch(int V, unordered_map<int, vector<Edge>>& graph, int maxtime)
{
	int left = 0, right = 1e6, result = -1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (dijkstra(1, V, graph, maxtime, mid))
		{
			result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return result;
}

void input() {
	unordered_map<int, vector<Edge>> graph;
	int v, e, t;
	cin >> v >> e >> t;
	for (int i = 0; i < e; i++)
	{
		int f, s, c, time;
		cin >> f >> s >> c >> time;
		graph[f].push_back({ s, c, time });
	}
	cout << binarySearch(v, graph, t);
}

/*First combined solution 6/10:
struct Edge {
	int to;
	int weight;
	int duration;
};

struct Node {
	int index;
	int cost;
	int time;

	bool operator<(const Node& rhs) const {
		return cost > rhs.cost;
	}
};

int dijkstra(int start, int V, unordered_map<int, vector<Edge>>& graph, int maxtime)
{
	vector<pair<int, int>> distances(V + 1, {INT_MAX, INT_MAX});
	priority_queue<Node> pq;
	distances[start] = { 0, 0 };
	pq.push({ start, 0, 0 });

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		if (curr.index == V && curr.time <= maxtime)
			return curr.cost;

		if (curr.cost > distances[curr.index].first &&
			curr.time > distances[curr.index].second)
			continue;

		for (auto edge : graph[curr.index])
		{
			int newCost = max(curr.cost, edge.weight);
			int newTime = curr.time + edge.duration;

			if (newTime > maxtime)
				continue;

			if ((newCost > distances[edge.to].first && newTime < distances[edge.to].second) ||
				(newCost < distances[edge.to].first && newTime < distances[edge.to].second))
			{
				distances[edge.to].first = newCost;
				distances[edge.to].second = newTime;
				pq.push({ edge.to, newCost, newTime });
			}
		}
	}

	return -1;
}

void input() {
	unordered_map<int, vector<Edge>> graph;
	int v, e, t;
	cin >> v >> e >> t;
	for (int i = 0; i < e; i++)
	{
		int f, s, c, time;
		cin >> f >> s >> c >> time;
		graph[f].push_back({ s, c, time });
	}

	cout << dijkstra(1, v, graph, t);
}*/