#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
using namespace std;

// Sum of tol taxes for curr road
void getSum()
{
	int n, m;
	cin >> n >> m;
	unordered_map<string, long long> map;
	for (int i = 0; i < n; i++)
	{
		string city;
		long long tax;
		cin >> city >> tax;
		map[city] = tax;
	}

	long long sum = 0;
	for (int i = 0; i < m; i++)
	{
		string city;
		cin >> city;
		sum += map[city];
	}
	cout << sum;
}