#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
	int n = nums.size();
	stack<pair<int, int>> currNums;
	vector<int> result(n, -1);

	for (int i = 0; i < n; i++)
	{
		int curr = nums[i];
		while (!currNums.empty() && curr > currNums.top().first)
		{
			result[currNums.top().second] = curr;
			currNums.pop();
		}

		currNums.emplace(nums[i], i);
	}

	for (int i = 0; i < n; i++)
	{
		int curr = nums[i];
		while (!currNums.empty() && curr > currNums.top().first)
		{
			result[currNums.top().second] = curr;
			currNums.pop();
		}
	}

	return result;
}