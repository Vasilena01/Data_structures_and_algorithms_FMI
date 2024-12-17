#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void bfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& pathsLen)
{
	queue<int> q;
	unordered_set<int> visited;
	visited.insert(0);
	q.push(0);
	pathsLen[0] = 0;

	while (!q.empty())
	{
		int curr = q.back();
		q.pop();
		for (int neighbor : graph[curr])
		{
			if (!visited.count(neighbor))
			{
				visited.insert(neighbor);
				q.push(neighbor);
				pathsLen[neighbor] = pathsLen[curr] + 1;
			}
		}

	}
}

bool dfsCycle(int curr, unordered_map<int, unordered_set<int>>& graph, vector<int>& visited)
{
	/*0 - unvisited
		1 - in progress
		2 - visited	*/

	visited[curr] = 1;

	for (int neighbor : graph[curr])
	{
		if (visited[neighbor] == 1)
			return true;

		if (visited[neighbor] == 2)
			continue;

		if (dfsCycle(neighbor, graph, visited))
			return true;
	}

	visited[curr] = 2;
	return false;
}

bool topologicalSortCycle(int curr, unordered_map<int, unordered_set<int>>& graph, 
	vector<int>& visited, vector<int>& res)
{
	if (visited[curr] == 1)
		return false;

	if (visited[curr] == 2)
		return true;

	visited[curr] = 1;
	for (int neighbor : graph[curr])
	{
		if (!topologicalSortCycle(neighbor, graph, visited, res))
			return false;
	}

	visited[curr] = 2;
	res.push_back(curr);
	return true;
}