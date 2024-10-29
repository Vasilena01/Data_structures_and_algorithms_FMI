#include <iostream>
#include <vector>
using namespace std;

/*Zad k1_2023
void getUniqueIndicies(string str)
{
	int n = str.length();
	vector<int> freq(256);
	vector<int> uniqueIndicies;

	for (int i = 0; i < n; i++)
		freq[str[i]]++;

	for (int i = 0; i < n; i++)
	{
		if (freq[str[i]] == 1)
			uniqueIndicies.push_back(i);
	}

	for (int i = 0; i < uniqueIndicies.size(); i++)
		cout << uniqueIndicies[i];
}*/

/*Zad prakt 2

void merge(vector<pair<int, int>>& pairs, vector<int>& counts, int left, int mid, int right)
{
	int n = pairs.size();
	vector<pair<int, int>> temp(right - left + 1);
	int leftInd = left;
	int rightInd = mid + 1;
	int index = 0;
	int rightCount = 0;

	while (leftInd <= mid && rightInd <= right)
	{
		if (pairs[leftInd].first <= pairs[rightInd].first)
		{
			counts[pairs[leftInd].second] += rightCount;
			temp[index++] = pairs[leftInd++];
		}
		else
		{
			rightCount++;
			temp[index++] = pairs[rightInd++];
		}
	}

	while (leftInd <= mid)
	{
		counts[pairs[leftInd].second] += rightCount;
		temp[index++] = pairs[leftInd++];
	}

	while (rightInd <= right)
	{
		temp[index++] = pairs[rightInd++];
	}

	for (int i = 0; i < temp.size(); i++)
		pairs[left + i] = temp[i];
}

void mergeSort(vector<pair<int, int>>& pairs, vector<int>& counts, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	mergeSort(pairs, counts, left, mid);
	mergeSort(pairs, counts, mid + 1, right);

	merge(pairs, counts, left, mid, right);
}

vector<int> getCounts(vector<int>& nums)
{
	int n = nums.size();
	vector<pair<int, int>> pairs;
	vector<int> counts(n, 0);

	for (int i = 0; i < n; i++)
		pairs.push_back({ nums[i], i });

	mergeSort(pairs, counts, 0, n - 1);

	return counts;
}*/

int main()
{
	/*K1_2023
	string str;
	cin >> str;
	getUniqueIndicies(str);*/

	/*Zad ot practikum
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	vector<int> counts = getCounts(nums);

	for (int i = 0; i < n; i++)
		cout << counts[i];*/
}