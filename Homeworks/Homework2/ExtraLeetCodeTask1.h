#pragma once
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& nums, int l, int r, int target)
{
	while (l < r)
	{
		int mid = l + (r - l) / 2;

		if (nums[mid] == target)
			return mid;

		if (target > nums[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}

	if (nums[l] != target)
		return -1;

	return l;
}

int search(vector<int>& nums, int target) {
	int maxInd = 0;
	int n = nums.size();

	if (n == 1)
	{
		if (target != nums[0])
			return -1;
		else
			return 0;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (nums[i + 1] < nums[i])
		{
			maxInd = i;
			break;
		}
	}

	if (target >= nums[0] && target <= nums[maxInd])
		return binarySearch(nums, 0, maxInd, target);
	else
		return binarySearch(nums, maxInd + 1, n - 1, target);
}

int findMin(vector<int>& nums) {
	int minInd = 0;
	int n = nums.size();

	for (int i = 0; i < n - 1; i++)
	{
		if (nums[i + 1] < nums[i])
		{
			minInd = i + 1;
			break;
		}
	}

	return nums[minInd];
}