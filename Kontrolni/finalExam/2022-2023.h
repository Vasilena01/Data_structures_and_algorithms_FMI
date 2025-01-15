#pragma once
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <climits>
#include <iostream>
#include <bitset>
#include <numeric>
using namespace std;

/*Task 2 - get components count, with nodesCount % k == 0*/
void dfs(int curr, unordered_map<int, unordered_set<int>>& graph, 
	vector<bool>& visited, int& count)
{
	visited[curr] = true;
	count++;
	for (int neighbor : graph[curr])
	{
		if (!visited[neighbor])
			dfs(neighbor, graph, visited, count);
	}
}

void input2()
{
	int v, e, k;
	cin >> v >> e >> k;
	unordered_map<int, unordered_set<int>> graph;
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].insert(y);
		graph[y].insert(x);
	}

	vector<bool> visited(v);
	int count = 0;
	for (int i = 0; i < v; i++)
	{
		int currCount = 0;
		if (!visited[i])
		{
			dfs(i, graph, visited, currCount);
			if(currCount % k == 0)
				count++;
		}
	}
	cout << count;
}

/*Task 4 - get certain path len without visiting certain nodes*/
int bfs(int start, int end, unordered_map<int, unordered_set<int>>& graph,
	unordered_set<int>& shouldNotVisit)
{
	queue<int> q;
	unordered_set<int> visited;
	q.push(start);
	visited.insert(start);
	int resLen = -1;
	int len = 0;

	while (!q.empty())
	{
		int currlen = q.size();
		int curr = q.front();
		q.pop();

		while (currlen > 0)
		{
			if (curr == end)
			{
				resLen = len;
				break;
			}

			visited.insert(curr);
			for (int neighbor : graph[curr])
			{
				if (!visited.count(neighbor) && !shouldNotVisit.count(neighbor))
					q.push(neighbor);
			}
			currlen--;
		}

		if (resLen != -1)
			break;

		len++;
	}
	return resLen;
}
void input4()
{
	int n, m;
	cin >> n >> m;
	unordered_map<int, unordered_set<int>> graph;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].insert(y);
		graph[y].insert(x);
	}

	int p;
	cin >> p;
	vector<int> path;
	unordered_set<int> shouldNotVisit;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		path.push_back(x);
		shouldNotVisit.insert(x);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int y;
		cin >> y;
		shouldNotVisit.insert(y);
	}

	shouldNotVisit.erase(path[0]);
	int resPath = 0;
	for (int i = 1; i < path.size(); i++)
	{
		shouldNotVisit.erase(path[i]);
		int currPath = bfs(path[i - 1], path[i], graph, shouldNotVisit);
		resPath += currPath;
	}
	cout << resPath;
}
