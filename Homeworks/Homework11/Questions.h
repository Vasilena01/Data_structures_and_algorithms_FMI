#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

struct UnionFind
{
	vector<int> parent;
	vector<int> rank;

	UnionFind(int n)
	{
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int x)
	{
		if (x != parent[x])
			parent[x] = find(parent[x]);
		return parent[x];
	}

	void unite(int x, int y) {
		int parentX = find(x);
		int parentY = find(y);

		if (parentX == parentY)
			return;

		if (rank[parentX] > rank[parentY]) {
			parent[parentY] = parentX;
		}
		else if (rank[parentX] < rank[parentY]) {
			parent[parentX] = parentY;
		}
		else {
			parent[parentY] = parentX;
			rank[parentX]++;
		}
	}
};
void questions()
{
	int v, e;
	cin >> v >> e;
	UnionFind uf(v + 1);

	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		uf.unite(x, y);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int option, st, end;
		cin >> option >> st >> end;

		if (option == 1)
		{
			if (uf.find(st) == uf.find(end))
				cout << 1;
			else
				cout << 0;
		}
		else
			uf.unite(st, end);
	}
}