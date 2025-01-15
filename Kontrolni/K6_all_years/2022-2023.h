#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

/*Task 1 - count of areas in a city*/
void dfs(int curr, unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited)
{
	visited[curr] = true;

	for (int neighbor : graph[curr])
	{
		if (!visited[neighbor])
			dfs(neighbor, graph, visited);
	}
}
void input()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int v, e;
		cin >> v >> e;
		unordered_map<int, unordered_set<int>> graph;
		for (int j = 0; j < e; j++)
		{
			int x, y;
			cin >> x >> y;
			graph[x].insert(y);
			graph[y].insert(x);
		}

		vector<bool> visited(v, false);
		int count = 0;
		for (int j = 0; j < v; j++)
		{
			if (!visited[j])
			{
				dfs(j, graph, visited);
				count++;
			}
		}
		cout << count << " ";
	}
}

/*Task 2 - get the cost of a certain path in graph or -1*/
void getInput()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, unordered_map<int, int>> graph;
	for (int i = 0; i < e; i++)
	{
		int f, s, c;
		cin >> f >> s >> c;
		graph[f].insert({s, c});
		graph[s].insert({ f, c });
	}

	int n;
	cin >> n;
	queue<int> path;
	for (int i = 0; i < n; i++)
	{
		int vertex;
		cin >> vertex;
		path.push(vertex);
	}

	int pathLen = 0;
	while (path.size() != 1)
	{
		int start = path.front();
		path.pop();
		int end = path.front();

		if (graph[start].count(end))
			pathLen += graph[start][end];
		else
		{
			cout << -1;
			return;
		}
	}
	cout << pathLen;
}

/*Task 3 - is cyclic graph */
bool dfsCycle(int curr, unordered_map<int, unordered_map<int, int>>& graph, vector<int>& state)
{
	state[curr] = 0;

	for (auto neighbor : graph[curr])
	{
		if (state[neighbor.first] == 1)
			continue;

		if (state[neighbor.first] == 0)
			return true;

		if (dfsCycle(neighbor.first, graph, state))
			return true;
	}

	state[curr] = 1;
	return false;
}
void isCyclicGraph()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int v, e;
		cin >> v >> e;
		unordered_map<int, unordered_map<int, int>> graph;
		for (int j = 0; j < e; j++)
		{
			int f, s, c;
			cin >> f >> s >> c;
			graph[f - 1].insert({ s - 1, c });
		}

		bool hasCycle = false;
		vector<int> state(v, -1);
		for (int j = 0; j < v; j++)
		{
			if (dfsCycle(j, graph, state))
			{
				hasCycle = true;
				break;
			}
		}

		if (hasCycle)
			cout << "true ";
		else
			cout << "false ";
	}
}