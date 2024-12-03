#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

size_t hashString(const string& str)
{
	const int p = 31;
	const int m = 1e9 + 9;
	size_t hashValue = 0;
	size_t p_pow = 1;
	vector<size_t> charCount(26 + 1);
	for (char ch : str)
		charCount[ch - 'a']++;

	for (size_t count : charCount)
	{
		hashValue = (hashValue + count * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hashValue;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<size_t, vector<string>> hashedStrs;
	vector<vector<string>> res;
	for (string str : strs)
	{
		size_t hash = hashString(str);
		hashedStrs[hash].push_back(str);
	}
	for (auto it = hashedStrs.begin(); it != hashedStrs.end(); it++)
		res.push_back(it->second);
}