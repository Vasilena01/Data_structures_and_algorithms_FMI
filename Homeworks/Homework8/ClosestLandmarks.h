#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

double getDistance(int x, int y, pair<int, int> other)
{
	return sqrt(pow((other.first - x), 2) + pow((other.second - y), 2));
}

void buildMinHeap()
{
	int x, y, n, k;
	cin >> x >> y >> n >> k;
	vector<pair<int, int>> points;
	for (int i = 0; i < n; i++)
	{
		int first, second;
		cin >> first >> second;
		points.push_back({ first, second });
	}

	priority_queue<
		pair<double, pair<int, int>>,
		vector<pair<double, pair<int, int>>>,
		greater<pair<double, pair<int, int>>>
	> minHeap;

	for (const auto& point : points)
	{
		double dist = getDistance(x, y, point);
		minHeap.push({ dist, point });
	}

	for (int i = 0; i < k; i++)
	{
		pair<double, pair<int, int>> curr = minHeap.top();
		cout << curr.second.first << " " << curr.second.second << endl;
		minHeap.pop();
	}
}