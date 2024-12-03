#pragma once
#include <iostream>
#include <string>
using namespace std;

void getLenOfLongestSubstr()
{
	string s1, s2;
	cin >> s1 >> s2;

	int res = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		int iTemp = i;
		int j = 0;
		int currLen = 0;

		while (iTemp < s1.size() && j < s2.size())
		{
			if (s1[iTemp] == s2[j])
			{
				currLen++;
				res = max(res, currLen);
			}
			else
				currLen = 0;

			iTemp++;
			j++;
		}

	}
	cout << res;
}