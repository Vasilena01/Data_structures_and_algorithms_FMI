#pragma once
#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	vector<long long> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i <= amount; i++)
	{
		for (int coin : coins)
		{
			if (i >= coin && coins[i] != INT_MAX)
				dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}
 }