#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sortByGrade(vector<string>& names, vector<int>& grades)
{
	// Bubble sort
	int size = names.size();

	int lastSwappedIndex = size - 1;
	for (int i = 0; i < size; i++)
	{
		int currentSwappedIndex = 0;
		for (int j = 0; j < lastSwappedIndex; j++)
		{
			if (grades[j] > grades[j + 1])
			{
				currentSwappedIndex = j;
				swap(grades[j], grades[j + 1]);
				swap(names[j], names[j + 1]);
			}
			else if (grades[j] == grades[j + 1])
			{
				if (names[j][0] < names[j + 1][0])
				{
					swap(names[j], names[j + 1]);
					swap(grades[j], grades[j + 1]);
				}
				else
					continue;
			}
		}

		if (currentSwappedIndex == 0)
			return;

		lastSwappedIndex = currentSwappedIndex;
	}
}