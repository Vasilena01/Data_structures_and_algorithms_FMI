#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getIndicies(vector<int>& nums)
{
	int n = nums.size();
	vector<pair<int, int>> pairs;
	vector<int> result(n);

	for (int i = 0; i < n; i++)
		pairs.push_back({ nums[i], i });

	sort(pairs.begin(), pairs.end());

	for (int i = 0; i < n; i++)
		result[pairs[i].second] = i;

	return result;
}