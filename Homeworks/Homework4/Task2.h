#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int getMinValue(queue<int>& people, int k)
{
	int min = people.front();
	for (int i = 0; i < k; i++)
	{
		int curr = people.front();
		if (curr < min)
			min = curr;
		people.pop();
		people.push(curr);
	}

	return min;
}
/*First slow solution*/
void getMinHardworkingCount()
{
	int n, k;
	cin >> n >> k;
	vector<int> people(n);

	for (int i = 0; i < n; i++)
		cin >> people[i];

	int minCount = 0;
	queue<int> currPeople;

	// Pushing the first k elements to the queue
	for (int i = 0; i < k; i++)
	{
		currPeople.push(people[i]);
	}

	minCount += getMinValue(currPeople, k);

	// Looping through the rest of people arr and 
	// executing pop and push to currPeople to get the minValue in each queue
	for (int i = k; i < n; i++)
	{
		currPeople.pop();
		currPeople.push(people[i]);
		minCount += getMinValue(currPeople, k);
	}

	cout << minCount;
}
/*Second fast solution - deque*/
void getMinHardworkingCount2()
{
	int n, k;
	cin >> n >> k;
	vector<int> people(n);

	for (int i = 0; i < n; i++)
		cin >> people[i];

	long long minCount = 0;
	deque<int> currIndicies;

	// Getting the first k indicies
	for (int i = 0; i < k; i++)
	{
		while (!currIndicies.empty() && people[currIndicies.back()] >= people[i])
			currIndicies.pop_back();
		currIndicies.push_back(i);
	}

	minCount += people[currIndicies.front()];

	//Getting the rest of the indicies
	for (int i = k; i < n; i++)
	{
		// Remove indicies outside the current set
		if (!currIndicies.empty() && currIndicies.front() <= i - k)
			currIndicies.pop_front();

		while (!currIndicies.empty() && people[currIndicies.back()] >= people[i])
			currIndicies.pop_back();

		currIndicies.push_back(i);
		minCount += people[currIndicies.front()];
	}
	cout << minCount;
}