#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void dequeTaskThird()
{
	int n;
	cin >> n;
	vector<int> people(n);
	for (int i = 0; i < n; i++)
		cin >> people[i];

	deque<int> currPeopleDeque;

	for (int i = 0; i < n; i++)
	{
		int curr = people[i];
		while (!currPeopleDeque.empty() && curr < 0 && currPeopleDeque.back() > 0)
		{
			// If the intelect of the curr person is < than the last added in deque
			if (abs(curr) < currPeopleDeque.back())
			{
				// curr loses
				curr = 0; 
				break;
			}
			// If the intelect of the curr person is = to the last added in deque 
			else if (abs(curr) == currPeopleDeque.back())
			{
				// both lose
				curr = 0;
				currPeopleDeque.pop_back();
				break;
			}
			// While the curr person intelect is > that the last from deque
			else
			{
				// curr wins
				currPeopleDeque.pop_back();
			}
		}

		if(curr != 0)
			currPeopleDeque.push_back(curr);
	}

	int size = currPeopleDeque.size();
	for (int i = 0; i < size; i++)
	{
		cout << currPeopleDeque.front() << " ";
		currPeopleDeque.pop_front();
		if (currPeopleDeque.empty())
			break;
	}
}
