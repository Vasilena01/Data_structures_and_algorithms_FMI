#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

/*First solution - prim*/
int prim(int v, unordered_map<int, vector<int>>& graph, int start)
{
	queue<int> q;
	unordered_set<int> visited;
	int mstWeight = 0;
	q.push(start);

	while (!q.empty() && visited.size() < v)
	{
		int curr = q.front();
		q.pop();

		if (visited.count(curr))
			continue;

		visited.insert(curr);
		mstWeight++;
		for (auto neighbor : graph[curr])
		{
			if (visited.count(neighbor))
				continue;
			q.push(neighbor);
		}
	}

	if (visited.size() == v - 1)
		return mstWeight;
	return -1;
}

void input()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, vector<int>> graph;
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << prim(v + 1, graph, 1);
}

/*Second solution - union find*/
struct UnionFind
{
	vector<int> parent;
	vector<int> rank;
	int componentsCount = 0;
	UnionFind(int n)
	{
		parent.resize(n);
		rank.resize(n);
		componentsCount = n;
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] != x)
			parent[x] = find(parent[x]);
		return parent[x];
	}

	void unite(int x, int y)
	{
		int parentX = find(x);
		int parentY = find(y);

		if (parentX == parentY)
			return;

		if (rank[parentX] > rank[parentY])
			parent[parentY] = parentX;
		else if (rank[parentY] > rank[parentX])
			parent[parentX] = parentY;
		else
		{
			parent[parentY] = parentX;
			rank[parentX]++;
		}

		componentsCount--;
	}
};

void input2()
{
	int v, e;
	cin >> v >> e;
	UnionFind uf(v);

	if (v == 1 && e == 0)
	{
		cout << 0;
		return;
	}

	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		uf.unite(x - 1, y - 1);

		if (e == 1 && x == y)
		{
			cout << 0;
			return;
		}

		if (uf.componentsCount == 1)
		{
			cout << i + 1;
			return;
		}
	}
	cout << -1;
}