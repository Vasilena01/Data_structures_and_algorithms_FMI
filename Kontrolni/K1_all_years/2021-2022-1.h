#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortInUniqueOrder(vector<int>& nums)
{
	int n = nums.size();
	int K = *max_element(nums.begin(), nums.end()) + 1;
	vector<int> count(K);

	for (int i = 0; i < n; i++)
	{
		if (count[nums[i]] < 1)
			count[nums[i]]++;
	}

	for (int i = 0; i < K; i++)
	{
		if(count[i] != 0)
			cout << i << " ";
	}
}