#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void insertLexicographically(vector<int>& allNums, int num)
{
	for (auto it = allNums.begin(); it != allNums.end(); it++)
	{
		if (*it > num)
		{
			allNums.insert(it, num);
			return;
		}
	}
	allNums.push_back(num);
}

void printSubSequenceLexicographically()
{
	int n, m;
	cin >> n >> m;

	unordered_set<int> currNums;
	vector<int> allNums;

	for (int i = 0; i < m; i++)
	{
		int curr;
		cin >> curr;
		currNums.insert(curr);
		allNums.push_back(curr);
	}

	for (int i = 1; i <= n; i++)
	{
		// If i is not in the unordered_set
		if (currNums.find(i) == currNums.end())
			insertLexicographically(allNums, i);
	}

	for (int num : allNums)
		cout << num << " ";
}