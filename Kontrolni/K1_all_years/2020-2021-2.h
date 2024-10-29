#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeReversed(vector<int>& nums, vector<int>& result, int left, int mid, int right)
{
	int leftInd = left;
	int rightInd = mid;
	int index = left;

	while (leftInd <= mid - 1 && rightInd <= right)
	{
		if (nums[leftInd] >= nums[rightInd])
			result[index++] = nums[leftInd++];
		else
			result[index++] = nums[rightInd++];
	}

	while(leftInd <= mid - 1)
		result[index++] = nums[leftInd++];

	while (rightInd <= right)
		result[index++] = nums[rightInd++];

	for (int i = left; i <= right; i++)
		nums[i] = result[i];
}

void mergeSortNums(vector<int>& nums, vector<int>& temp, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSortNums(nums, temp, left, mid);
	mergeSortNums(nums, temp, mid + 1, right);

	mergeReversed(nums, temp, left, mid + 1, right);
}