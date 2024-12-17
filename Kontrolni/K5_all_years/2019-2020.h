#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void bfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited,
	vector<int>& pathsLen)
{
	visited.insert(0);
	pathsLen[0] = 0;
	queue<int> q;
	q.push(0);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int neighbor : graph[curr])
		{
			if (!visited.count(neighbor))
			{
				visited.insert(neighbor);
				pathsLen[neighbor] = pathsLen[curr] + 1;
				q.push(neighbor);
			}
		}
	}
}

void getMinPathsWithLenK()
{
	unordered_map<int, unordered_set<int>> graph;
	unordered_set<int> visited;
	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x - 1].insert(y - 1);
		graph[y - 1].insert(x - 1);
	}

	vector<int> pathsLen(v, -1);
	bfs(graph, visited, pathsLen);
	vector<int> res;
	for (int i = 0; i < pathsLen.size(); i++)
	{
		if (pathsLen[i] == k)
			res.push_back(i + 1);
	}

	for (int num : res)
		cout << num << " ";
}