#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
using namespace std;

// Australian krokodile - cout all unique words from all sentences, which dont occur
// in the other sentences
void getUniqueWords()
{
	string word;
	unordered_map<string, long long> map1;
	unordered_map<string, long long> map2;
	set<string> res;
	while (cin >> word)
	{
		map1[word]++;
		char c = cin.peek();
		if (c == '\n')
			break;
	}

	while (cin >> word)
	{
		map2[word]++;
		char c = cin.peek();
		if (c == '\n')
			break;
	}

	for (auto it = map2.begin(); it != map2.end(); it++)
	{
		if (map1.find(it->first) == map1.end() && it->second == 1)
			res.insert(it->first);
	}

	for (auto it = map1.begin(); it != map1.end(); it++)
	{
		if (map2.find(it->first) == map2.end() && it->second == 1)
			res.insert(it->first);
	}

	for (string word : res)
		cout << word << endl;
}

// Dynamic programming - get path sum in matrix
struct hashPair
{
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& pair) const {
		return hash<T1>()(pair.first) ^ (hash<T2>()(pair.second) << 1);
	}
};

void getPathSum()
{
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	unordered_set<pair<int, int>, hashPair> specialCoordinats;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int curr;
			cin >> curr;
			matrix[i][j] = curr;
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int f, s;
		cin >> f >> s;
		specialCoordinats.insert({ f, s });
	}

	unordered_map<pair<int, int>, int, hashPair> dp;
	dp[{0, 0}] = matrix[0][0];
	for (int i = 1; i < n; i++)
		dp[{i, 0}] = dp[{i - 1, 0}] + matrix[i][0];

	for (int i = 1; i < n; i++)
		dp[{0, i}] = dp[{0, i - 1}] + matrix[0][i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			int curr = matrix[i][j];
			dp[{i, j}] = max(dp[{i - 1, j}] + curr, dp[{i, j - 1}] + curr);

			if (specialCoordinats.find({ i, j }) != specialCoordinats.end())
				dp[{i, j}] = max(dp[{i, j}], dp[{i - 1, j - 1}] + curr);
		}
	}
	cout << dp[{n - 1, n - 1}];
}