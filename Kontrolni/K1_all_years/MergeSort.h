#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right)
{
	int leftInd = left;
	int rightInd = mid;
	int index = left;

	while (leftInd <= mid - 1 && rightInd <= right)
	{
		if (nums[leftInd] <= nums[rightInd])
			temp[index++] = nums[leftInd++];
		else
			temp[index++] = nums[rightInd++];
	}

	while(leftInd <= mid - 1)
		temp[index++] = nums[leftInd++];

	while (rightInd <= right)
		temp[index++] = nums[rightInd++];

	for (int i = left; i <= right; i++)
		nums[i] = temp[i];

}

void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(nums, temp, left, mid);
	mergeSort(nums, temp, mid + 1, right);

	merge(nums, temp, left, mid + 1, right);
}