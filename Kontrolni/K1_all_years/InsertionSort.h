#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); i++)
	{
		int currElement = nums[i];
		int prevIndex = i - 1;

		while (prevIndex >= 0 && nums[prevIndex] > currElement)
		{
			nums[prevIndex + 1] = nums[prevIndex];
			prevIndex--;
		}

		nums[prevIndex + 1] = currElement;
	}
}