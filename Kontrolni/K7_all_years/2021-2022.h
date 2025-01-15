#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

struct Edge
{
	int to;
	int weight;
};

struct Node
{
	int index;
	int cost;
	bool operator<(const Node& other) const
	{
		return cost > other.cost;
	}
};

void dijkstra(int v, int start, unordered_map<int, vector<Edge>>& graph,
	unordered_set<int>& badLuckNums, vector<vector<int>>& shortestPaths)
{
	vector<int> distances(v, INT_MAX);
	priority_queue<Node> pq;
	distances[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		auto curr = pq.top();
		pq.pop();

		if (curr.cost > distances[curr.index])
			continue;

		for (auto neighbor : graph[curr.index])
		{
			if (badLuckNums.count(neighbor.weight))
				continue;

			int newCost = curr.cost + neighbor.weight;
			if (newCost < distances[neighbor.to])
			{
				distances[neighbor.to] = newCost;
				if(neighbor.to != curr.index)
					pq.push({ neighbor.to, newCost });
			}
		}
	}

	shortestPaths[start] = distances;
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

	unordered_set<int> badLuckNums;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		badLuckNums.insert(n);
	}

	vector<vector<int>> shortestPaths(v, vector<int>(v, INT_MAX));
	for (int i = 0; i < v; i++)
	{
		dijkstra(v, i, graph, badLuckNums, shortestPaths);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int length;
		cin >> length;
		vector<int> path(length);
		for (int j = 0; j < length; j++)
			cin >> path[j];

		bool isValidPath = true;
		for (int j = 1; j < length; j++)
		{
			if (shortestPaths[path[j - 1]][path[j]] == INT_MAX)
			{
				isValidPath = false;
				break;
			}
		}
		cout << isValidPath;
	}
}

//Second solution
void input2()
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

	unordered_set<int> badLuckNums;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		badLuckNums.insert(n);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int len;
		cin >> len;
		vector<int> path(len);
		for (int j = 0; j < len; j++)
		{
			cin >> path[j];
		}

		for (int j = 1; j < len; j++)
		{
			bool isPath = false;
			int start = path[j - 1];
			int end = path[j];

			for (auto neighbor : graph[start])
			{
				if (neighbor.to == end && !badLuckNums.count(neighbor.weight))
				{
					isPath = true;
					break;
				}
			}

			if (isPath == false)
			{
				cout << 0;
				break;
			}
		}
		cout << 1;
	}
}