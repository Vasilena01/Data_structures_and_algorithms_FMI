#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
using namespace std;

// Get str occurences from input
void printStrOccurences()
{
	int n;
	cin >> n;
	vector<string> words;
	unordered_map<string, long long> map;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		words.push_back(word);
		map[word]++;
	}

	for (string word : words)
		cout << map[word] << " ";
}

// Get sum of numbers which occur odd num of times
void getSumOfOddNumOccurences()
{
	int n;
	cin >> n;
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		map[num]++;
	}
	int sum = 0;
	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (it->second % 2 != 0)
			sum += it->first*it->second;
	}
	cout << sum;
}

// Remove duplicates from arr and place them in the correct order at the back
void removeDuplicates()
{
	int n;
	cin >> n;
	vector<int> nums;
	vector<int> res;
	unordered_map<int, bool> map;
	unordered_map<int, int> mapOccurences;
	for (int i = 0; i < n; i++)
	{
		int curr;
		cin >> curr;
		nums.push_back(curr);
		map[curr] = 0;
		mapOccurences[curr]++;
	}

	for (int i = 0; i < n; i++)
	{
		int curr = nums[i];
		if (mapOccurences[curr] == 1)
			res.push_back(curr);
	}

	for (int i = 0; i < n; i++)
	{
		int curr = nums[i];
		if (!map[curr] && mapOccurences[curr] > 1)
		{
			res.push_back(curr);
			map[curr] = 1;
		}
	}

	for (int num : res)
		cout << num << " ";
}