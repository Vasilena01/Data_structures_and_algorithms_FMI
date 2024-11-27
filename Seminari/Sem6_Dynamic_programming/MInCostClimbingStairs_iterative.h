#pragma once
#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	int minCosts[10001]{ 0 };
	
	minCosts[0] = cost[0];
	minCosts[1] = cost[1];

	for (int i = 2; i < cost.size(); i++)
	{
		minCosts[i] = min(minCosts[i - 1], minCosts[i - 2]) + cost[i];
	}

	return min(minCosts[cost.size() - 1], minCosts[cost.size() - 2]);
}