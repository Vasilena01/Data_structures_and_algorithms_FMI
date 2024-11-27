#pragma once
#include <iostream>
#include <vector>
using namespace std;

int minCosts[10001]{ 0 };
int getMinVal(vector<int>& cost, int index) {
    if (index == 0)
        return minCosts[0];
    if (index == 1)
        return minCosts[1];

    if (minCosts[index] == 0)
    {
        minCosts[index] = min(getMinVal(cost, index - 1),
            getMinVal(cost, index - 2)) + cost[index];
    }

    return minCosts[index];
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    if (n >= 1)
        minCosts[0] = cost[0];
    if (n >= 2)
        minCosts[1] = cost[1];

    return min(getMinVal(cost, n - 1), getMinVal(cost, n - 2));
}