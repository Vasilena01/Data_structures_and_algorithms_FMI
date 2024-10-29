#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& skills, long long teamsCount, long long maxSum)
{
    int n = skills.size();
    long long currTeamsCount = 1;
    long long currSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (currSum + skills[i] > maxSum)
        {
            currTeamsCount++;
            currSum = 0;
        }
        else
            currSum += skills[i];

        if (currTeamsCount > teamsCount)
            return false;
    }

    return true;
}

int minimizeMaxSum(vector<int>& skills, long long teamsCount)
{
	int n = skills.size();
	long long left = *max_element(skills.begin(), skills.end());
	long long right = 0;

	for (int i = 0; i < n; i++)
		right += skills[i];

	while (left < right)
	{
		long long mid = left + (right - left) / 2;
		if (isPossible(skills, teamsCount, mid))
			right = mid;
		else
			left = mid + 1;
	}

	return left;
}