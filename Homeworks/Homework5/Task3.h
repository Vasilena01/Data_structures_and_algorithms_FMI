#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node_third
{
	vector<Node_third*> children;
	pair<int, int> data;
	Node_third(int value, int index) {
		data.first = value;
		data.second = index;
	}
};

vector<int> startTimes, endTimes;
int timer = 0;

Node_third* getNode(vector<Node_third*>& nodes, int value)
{
	if (nodes.empty())
	{
		Node_third* newNode = new Node_third(value, 0);
		nodes.push_back(newNode);
		return newNode;
	}

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i]->data.first == value)
			return nodes[i];
	}

	Node_third* newNode = new Node_third(value, nodes.size());
	nodes.push_back(newNode);
	return newNode;
}

void dfs(Node_third* curr)
{
	startTimes[curr->data.second] = timer++;
	for (int i = 0; i < curr->children.size(); i++)
		dfs(curr->children[i]);
	endTimes[curr->data.second] = timer++;
}

bool isChild(int first, int second)
{
	return startTimes[first] < startTimes[second] &&
		endTimes[first] > endTimes[second];
}

void checkForRelationship()
{
	int n;
	cin >> n;
	vector<Node_third*> nodes;
	vector<pair<int, int>> values(n - 1);

	for (int i = 0; i < n - 1; i++)
		cin >> values[i].first >> values[i].second;

	int q;
	cin >> q;
	vector<pair<int, int>> indicies(q);
	for (int i = 0; i < q; i++)
		cin >> indicies[i].first >> indicies[i].second;

	for (int i = 0; i < n - 1; i++)
	{
		Node_third* curr = getNode(nodes, values[i].first);
		Node_third* newNode = new Node_third(values[i].second, nodes.size());
		curr->children.push_back(newNode);
		nodes.push_back(newNode);
	}

	startTimes.resize(n);
	endTimes.resize(n);
	dfs(nodes[0]);

	for (int i = 0; i < q; i++)
	{
		int first = indicies[i].first;
		int second = indicies[i].second;

		if (isChild(first, second))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}

