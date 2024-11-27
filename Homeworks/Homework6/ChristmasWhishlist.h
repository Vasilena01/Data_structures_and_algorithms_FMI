#pragma once
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1000000007;
int dp[10081]{ 0 };
void shoppingPrep()
{
	int n;
	cin >> n;
	vector<int> times(n);
	for (int i = 0; i < n; i++)
		cin >> times[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 10080; j >= times[i]; j--)
		{
			dp[j] = (dp[j] + dp[j - times[i]]) % MOD;
		}
	}

	int count = 0;
	for (int i = 0; i <= 10080; i++)
	{
		count = (count + dp[i]) % MOD;
	}

	cout << count;
}