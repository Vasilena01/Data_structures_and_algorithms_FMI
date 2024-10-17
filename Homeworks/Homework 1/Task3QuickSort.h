#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Sorting the results with quick sort

int partition(vector<pair<string, int>>& results, int low, int high)
{
	int pivot = results[high].second;
	int l = low;

	for (int j = l; j < high; j++)
	{
		if (results[j].second > pivot || results[j].second == pivot && 
			results[j].first < results[high].first)
		{
			swap(results[l], results[j]);
			l++;
		}
	}

	swap(results[l], results[high]);
	return l;
}

void sortResults(vector<pair<string, int>>& results, int low, int high)
{
	if (low < high)
	{
		int pi = partition(results, low, high);

		sortResults(results, low, pi - 1);
		sortResults(results, pi + 1, high);
	}
}
