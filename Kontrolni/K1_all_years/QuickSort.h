#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int low, int high)
{
	int pivot = nums[high];
	int l = low;

	for (int j = low; j < high; j++)
	{
		if (nums[j] <= pivot)
		{
			swap(nums[j], nums[l]);
			l++;
		}
	}

	swap(nums[l], nums[high]);
	return l;
}

void quickSort(vector<int>& nums, int low, int high)
{
	if (low >= high)
		return;

	int pi = partition(nums, low, high);

	quickSort(nums, low, pi - 1);
	quickSort(nums, pi + 1, high);
}