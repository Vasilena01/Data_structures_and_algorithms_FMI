#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

/*Task 1 - path in graph*/
void dfsComponents(int curr, unordered_map<int, unordered_set<int>>& graph,
	vector<bool>& visited, vector<int>& componentsIndicies, int& count)
{
	visited[curr] = true;
	componentsIndicies[curr] = count;
	for (int neighbor : graph[curr])
	{
		if (!visited[neighbor])
			dfsComponents(neighbor, graph, visited, componentsIndicies, count);
	}
}
void isPathInGraph()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, unordered_set<int>> graph;
	for (int i = 0; i < e; i++)
	{
		int f, s;
		cin >> f >> s;
		graph[f - 1].insert(s - 1);
		graph[s - 1].insert(f - 1);
	}

	vector<int> componentsIndicies(v, 0);
	vector<bool> visited(v, 0);
	int count = 1;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			dfsComponents(i, graph, visited, componentsIndicies, count);
		}
		count++;
	}

	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << (componentsIndicies[s - 1] == componentsIndicies[e - 1]) << " ";
	}
}