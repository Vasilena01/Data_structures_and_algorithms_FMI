#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& nums)
{
	int n = nums.size();
	int K = *max_element(nums.begin(), nums.end()) + 1;
	vector<int> counts(K);
	vector<int> output(n);

	for (int i = 0; i < n; i++)
		counts[nums[i]]++;

	for (int i = 1; i < K; i++)
		counts[i] += counts[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		output[counts[nums[i]] - 1] = nums[i];
		counts[nums[i]]--;
	}

	for (int i = 0; i < n; i++)
		nums[i] = output[i];
}