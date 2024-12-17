#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

/*Tasks - graph*/
void dfs(int curr, unordered_map<int, unordered_set<int>>& graph, 
	vector<int>& visited, int compCount)
{
	visited[curr] = compCount;

	for (int neighbor : graph[curr])
	{
		if (visited[neighbor] == -1)
			dfs(neighbor, graph, visited, compCount);
	}
}
void isPathBetweenTwoNodes()
{
	int v, e;
	cin >> v >> e;
	unordered_map<int, unordered_set<int>> graph;
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x - 1].insert(y - 1);
		graph[y - 1].insert(x - 1);
	}

	vector<int> visited(v, -1);

	int compCount = 1;
	for (int i = 0; i < v; i++)
	{
		if (visited[i] == -1)
		{
			dfs(i, graph, visited, compCount);
		}
		compCount++;
	}

	int start, dest, q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> start >> dest;
		if (visited[start - 1] == visited[dest - 1])
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
}

/*Tasks - priority_queue*/
void makeEachFruitWithEqualWeight()
{
	priority_queue<int, vector<int>, greater<>> minHeap;
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		minHeap.push(num);
	}

	int count = 0;
	while (minHeap.top() < s && minHeap.size() > 1)
	{
		int first = minHeap.top();
		minHeap.pop();
		if (minHeap.size() == 0)
		{
			cout << -1;
			return;
		}

		first += 2*minHeap.top();
		minHeap.pop();
		minHeap.push(first);
		count++;
	}

	cout << (minHeap.top() >= s) ? count : -1;
}

void add(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap,
	int num)
{

	if (maxHeap.size() == 0 || num < maxHeap.top())
		maxHeap.push(num);
	else
		minHeap.push(num);

	if (maxHeap.size() > minHeap.size() + 1)
	{
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}

	if (minHeap.size() > maxHeap.size() + 1)
	{
		maxHeap.push(minHeap.top());
		minHeap.pop();
	}
}

double findMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap)
{
	if (minHeap.size() == maxHeap.size())
		return (minHeap.top() + maxHeap.top()) / 2.0;
	else
		return minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
}

void input()
{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		add(maxHeap, minHeap, num);
		cout << findMedian(maxHeap, minHeap) << endl;
	}
}
