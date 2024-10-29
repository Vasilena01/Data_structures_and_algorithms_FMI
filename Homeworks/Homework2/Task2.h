#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Slow solution
int getCountOfNumsInInterval(vector<int>& weights, int min, int max)
{
	int n = weights.size();
	int left = 0;
	int right = n - 1;

	// Get the indicies of the interval elements
	while (left <= right)
	{
		if (weights[left] == min && weights[right] == max)
			break;

		if (weights[left] < min)
			left++;
		
		if (weights[right] > max)
			right--;
	}

	return right - left + 1;
}

int findBound(const vector<int>& weights, int num) {
    int left = 0, right = weights.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
		if (weights[mid] == num)
			return mid;

        if (weights[mid] < num) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

int getCountOfNumsInInterval(const vector<int>& weights, int min, int max) {
    int leftIndex = findBound(weights, min);

    int rightIndex = findBound(weights, max);

    return rightIndex - leftIndex + 1;
}*/

/*Final solution*/
int findBound(const vector<int>& weights, int num, bool isUpper) {
    int left = 0, right = weights.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (weights[mid] < num || (isUpper && weights[mid] == num))
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int getCountOfNumsInInterval(const vector<int>& weights, int min, int max) {
    int leftIndex = findBound(weights, min, false);

    int rightIndex = findBound(weights, max, true);

    return std::max(0, rightIndex - leftIndex);
}

void getNumberOfPlayers(vector<int>& weights, vector<pair<int, int>>& weightIntervals)
{
	int k = weightIntervals.size();
	sort(weights.begin(), weights.end());

	for (int i = 0; i < k; i++)
	{
		int count = getCountOfNumsInInterval(weights, weightIntervals[i].first,
			weightIntervals[i].second);
		cout << count;
	}
}