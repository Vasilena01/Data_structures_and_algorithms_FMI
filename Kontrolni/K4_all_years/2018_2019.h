#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
using namespace std;

// Get count of ids with not shipped items and count of not shipped items
void getCountOfNotShipped()
{
	int n;
	cin >> n;
	unordered_map<long long, int> map;
	for (int i = 0; i < n; i++)
	{
		long long id;
		cin >> id;
		map[id]++;
	}

	int sumProducts = 0;
	int sumIds = 0;
	for (auto it = map.begin(); it != map.end(); it++)
	{
		if (it->second % 10 != 0)
			sumIds++;
		sumProducts += it->second % 10;
	}

	cout << sumIds << " " << sumProducts;
}