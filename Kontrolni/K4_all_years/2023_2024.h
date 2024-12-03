#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Sentence anagram with hashing 2/4
size_t hashWord(const string& word)
{
	const int p = 31;
	const int m = 1e9 + 9;
	size_t hashValue = 0;
	size_t p_pow = 1;

	for (char ch : word)
	{
		hashValue = (hashValue + (ch - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return hashValue;
}

void sentenceAnagram()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int len1, len2;
		cin >> len1 >> len2;
		unordered_set<size_t> hash1;
		unordered_set<size_t> hash2;

		for (int i = 0; i < len1; i++)
		{
			string word;
			cin >> word;
			size_t h1 = hashWord(word);
			hash1.insert(h1);
		}

		for (int i = 0; i < len2; i++)
		{
			string word;
			cin >> word;
			size_t h2 = hashWord(word);
			hash2.insert(h2);
		}

		int count = 0;
		for (auto it = hash2.begin(); it != hash2.end(); it++)
		{
			if (hash1.find(*it) != hash1.end())
				count++;
		}

		if(count == hash2.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

void sentenceAnagram2()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int len1, len2;
		cin >> len1 >> len2;
		unordered_map<string, long long> map;

		for (int i = 0; i < len1; i++)
		{
			string word;
			cin >> word;
			map[word]++;
		}
		bool found = true;
		for (int i = 0; i < len2; i++)
		{
			string word;
			cin >> word;
			if (!map[word])
				found = false;
			map[word]--;
		}

		found == true ? cout << "Yes" : cout << "No";
	}
}