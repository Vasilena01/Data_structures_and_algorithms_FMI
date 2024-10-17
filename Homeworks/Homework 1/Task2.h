#pragma once
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int elementsCount)
{
	int size = arr.size() - elementsCount;
	for (int i = 1; i < size; i++)
	{
		int currElement = arr[i];
		int prevIndex = i - 1;

		while (prevIndex >= 0 && arr[prevIndex] > currElement)
		{
			arr[prevIndex + 1] = arr[prevIndex];
			prevIndex--;
		}

		arr[prevIndex + 1] = currElement;
	}
}
double getMedian(vector<int>& arr, int elementsCount)
{
	int n = arr.size() - elementsCount;
	if (n == 1)
		return arr[0];
	else if (n == 2)
		return (arr[0] + arr[1]) / 2.0;

	insertionSort(arr, elementsCount);
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	int middleElement = arr[n / 2];
	if (n % 2 != 0)
		return middleElement;
	else
		return (middleElement + arr[(n / 2) - 1]) / 2.0;
}