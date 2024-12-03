#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void getTimesBisMedianInSubset()
{
	int n, b;
	cin >> n >> b;
	vector<int> ranks(n);

	for (int i = 0; i < n; i++)
	{
		int curr;
		cin >> curr;
		if (curr < b)
			ranks[i] = -1;
		else if (curr > b)
			ranks[i] = 1;
		else
			ranks[i] = 0;
	}

	unordered_map<int, int> prefix_count;
	prefix_count[0] = 1;
	int prefix_sum = 0;
	int result = 0;
	bool seen = false;

	for (int i = 0; i < n; i++)
	{
		prefix_sum += ranks[i];
		if (ranks[i] == 0)
		{
			result += prefix_count[prefix_sum];
			result += prefix_count[prefix_sum - 1];
			seen = true;
		}
		prefix_count[prefix_sum]++;
	}

	cout << result+1;
}