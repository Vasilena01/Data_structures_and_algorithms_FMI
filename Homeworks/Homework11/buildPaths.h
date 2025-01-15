#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

struct Edge {
	int from, to, effort, cost, index;
	bool operator<(const Edge& other) const
	{
		if (effort == other.effort)
		{
			int myTotalCost = effort * cost;
			int otherTotalCost = other.effort * other.cost;
			return myTotalCost < otherTotalCost;
		}
		else
			return effort > other.effort;
	}
};

void prim(int v, unordered_map<int, vector<Edge>>& graph, vector<int>& indicies, int start)
{
	priority_queue<Edge> pq;
	unordered_set<int> visited;
	pq.push({ start, start, 0, 0, -1 });

	while (!pq.empty() && visited.size() < v)
	{
		auto curr = pq.top();
		pq.pop();

		if (visited.count(curr.to))
			continue;

		visited.insert(curr.to);
		if(curr.index != -1)
			indicies.push_back(curr.index);
		for (auto edge : graph[curr.to])
		{
			if (visited.count(edge.to))
				continue;
			pq.push(edge);
		}
	}

	if (visited.size() != v) {
		indicies.clear();
	}
}

void input()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, vector<Edge>> graph;
	for (int i = 0; i < e; i++)
	{
		int st, end, effort, cost;
		cin >> st >> end >> effort >> cost;
		graph[st].push_back({ st, end, effort, cost, i });
		graph[end].push_back({ end, st, effort, cost, i });
	}

	vector<int> indicies;
	prim(v, graph, indicies, 1);
	for (int index : indicies)
		cout << index+1 << endl;
}