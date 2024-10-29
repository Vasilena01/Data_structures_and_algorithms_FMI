#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getSumOfUnique(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	int first = 0, second = 0;
	int result = 0;

	while (first < nums1.size() && second < nums2.size())
	{
		if (nums1[first] < nums2[second])
			first++;
		else if (nums2[second] < nums1[first])
			second++;
		else if (nums1[first] == nums2[second])
		{
			result += nums1[first];
			first++;
			second++;
		}
	}

	cout << result;
}