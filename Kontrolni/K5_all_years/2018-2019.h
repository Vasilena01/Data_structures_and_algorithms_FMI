#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void bfsGetPathsLen(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited,
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

void getSumOfMinPaths()
{
	unordered_map<int, unordered_set<int>> graph;
	unordered_set<int> visited;
	int v;
	cin >> v;
	for (int i = 0; i < v; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].insert(y);
		graph[y].insert(x);
	}

	vector<int> pathsLen(3000, -1);
	bfsGetPathsLen(graph, visited, pathsLen);
	int sum = 0;
	for (int n : pathsLen)
	{
		if (n != -1)
			sum += n;
	}
	cout << sum << " ";
}