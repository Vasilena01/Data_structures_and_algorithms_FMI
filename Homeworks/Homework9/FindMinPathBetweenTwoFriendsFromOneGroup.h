#pragma once
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph
{
private:
	int numVerticies;
	vector<int>* adjList;
public:
	Graph(int v) : numVerticies(v), adjList(new vector<int>[v]) {};

	void add(int v, int w)
	{
		adjList[v].push_back(w);
		adjList[w].push_back(v);
	}

	int findMinPath(unordered_map<int, int>& map, int target)
	{
		vector<int> targetNodes;
		for (auto it : map)
		{
			if (it.second == target)
				targetNodes.push_back(it.first);
		}

		int startNode = targetNodes[0];
		vector<int> distances(numVerticies, INT_MAX);
		queue<int> traversalNodes; // remaining non visited nodes
		int shortest_path = INT_MAX;
		distances[startNode] = 0;
		traversalNodes.push(startNode);

		while (!traversalNodes.empty())
		{
			int curr = traversalNodes.front();
			traversalNodes.pop();

			for (int neighbor : adjList[curr])
			{
				if (distances[neighbor] == INT_MAX)
				{
					distances[neighbor] = distances[curr] + 1;
					traversalNodes.push(neighbor);

					if (map[neighbor] == target)
						shortest_path = min(shortest_path, distances[neighbor]);
				}
			}
		}
		return shortest_path == INT_MAX ? -1 : shortest_path;
	}
};

void getInput()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		g.add(x - 1, y - 1);
	}

	unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		map[i] = num;
	}

	int myFriendGroup;
	cin >> myFriendGroup;

	cout << g.findMinPath(map, myFriendGroup);
}