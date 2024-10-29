#include <iostream>
#include "2022_2023.h"
#include "2021-2022-1.h"
#include "2020-2021.h"
#include "2020-2021-2.h"
#include "QuickSort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"

int main()
{
	/*2022-2023
	int n;
	cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	vector<int> result = getIndicies(nums);
	for (int i = 0; i < n; i++)
		cout << result[i];*/

	/*2021-2022-1
	int n;
	cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sortInUniqueOrder(nums);*/

	/*2020-2021
	int n;
	cin >> n;
	vector<int> nums1(n);
	for (int i = 0; i < n; i++)
		cin >> nums1[i];

	int k;
	cin >> k;
	vector<int> nums2(k);
	for (int i = 0; i < k; i++)
		cin >> nums2[i];

	getSumOfUnique(nums1, nums2);*/

	/*2020-2021-2
	int n;
	cin >> n;
	vector<int> nums(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	vector<int> temp(nums.size());
	mergeSortNums(nums, temp, 0, n - 1);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i];*/

	/*Merge, quick, insertion + counting sort*/
	vector<int> nums = { 8, 9, 22, 3, 1, 0 };
	vector<int> temp(nums.size());
	//quickSort(nums, 0, nums.size() - 1);
	//countingSort(nums);
	//mergeSort(nums, temp, 0, nums.size() - 1);
	insertionSort(nums);

	for (int i = 0; i < nums.size(); i++)
		cout << nums[i];
}