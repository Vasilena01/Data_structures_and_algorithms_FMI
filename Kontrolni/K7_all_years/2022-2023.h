#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

int bfs(int v, int start, int end, unordered_map<int, unordered_set<int>>& graph,
	vector<int>& attractions, unordered_set<int>& shouldNotVisit)
{
	vector<bool> visited(v, false);
	queue<int> q;
	q.push(start);

	int result = -1;
	int currentLength = 0;
	while (!q.empty())
	{
		int length = q.size();
		while (length > 0)
		{
			int curr = q.front();
			q.pop();
			visited[curr] = 1;

			if (curr == end)
			{
				result = currentLength;
				break;
			}

			for (int neighbor : graph[curr])
			{
				if (!visited[neighbor] && !shouldNotVisit.count(neighbor))
				{
					q.push(neighbor);
				}
			}
			length--;
		}

		if (result != -1)
		{
			break;
		}
		currentLength++;
	}
	return result;
}

void input()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, unordered_set<int>> graph;
	for (int i = 0; i < e; i++)
	{
		int f, s;
		cin >> f >> s;
		graph[f].insert(s);
	}

	int k;
	cin >> k;
	unordered_set<int> shouldNotVisit;
	vector<int> attractions(k);
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		attractions.push_back(n);
		shouldNotVisit.insert(n);
	}

	int totalPath = 0;
	shouldNotVisit.erase(attractions[0]);
	for (int i = 1; i < k; i++)
	{
		shouldNotVisit.erase(attractions[i]);
		int currPath = bfs(v, attractions[i - 1], attractions[i], graph, attractions, shouldNotVisit);
		if (currPath == -1)
		{
			totalPath = -1;
			break;
		}

		totalPath += currPath;
	}
	cout << totalPath;
}