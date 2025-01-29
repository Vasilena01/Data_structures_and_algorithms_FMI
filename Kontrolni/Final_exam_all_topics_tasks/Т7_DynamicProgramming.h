#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

/*T1* - get ways to climb to n-th stair with 1 or 2 stairs*/
int ways[46]{ 0 };
int climbStairs(int n) {
    if (n == 1 || n == 2)
        return n;

    if (ways[n] == 0)
        ways[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return ways[n];
}

/*T2* - get minCost climbing stairs with 1 or 2 stairs*/
int minCosts[1001]{ 0 };
int minCostClimbingStairs(vector<int>& cost) {
    minCosts[0] = cost[0];
    minCosts[1] = cost[1];

    for (int i = 2; i < cost.size(); i++)
    {
        minCosts[i] = min(minCosts[i - 1], minCosts[i - 2]) + cost[i];
    }
    return min(minCosts[cost.size() - 1], minCosts[cost.size() - 2]);
}

/*T3 - get all unique paths in grid*/
int grid[101][101];
int uniquePaths(int m, int n) {
    for (int i = 0; i < n; i++)
    {
        grid[0][i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        grid[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }
    return grid[m - 1][n - 1];
}

/*T4* - all unique path in obstacle grid*/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> paths(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        if (obstacleGrid[0][i] == 1)
        {
            paths[0][i] = 0;
            break;
        }
        paths[0][i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            paths[i][0] = 0;
            break;
        }
        paths[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                paths[i][j] = 0;
                continue;
            }

            paths[i][j] = paths[i - 1][j] +
                paths[i][j - 1];
        }
    }
    return paths[m - 1][n - 1];
}

/*T5 - get max cost of path in a matrix with weights where we can go only - 
up and down and for some coordinats also diagonal*/
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};
void input5() {
    // For more memory efficient solution - sum all cells in the matrix itself,
    // without using another dp matrix
    int dp[1001][1001];
    int matrix[1001][1001];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + matrix[0][i];
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }

    int k;
    cin >> k;
    // Alternative to not writing the PairHash func - use another bool
    // matrix to store just the diagonal cells
    unordered_set<pair<int, int>, PairHash> diagonals;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        diagonals.insert({ x, y });
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max((dp[i - 1][j] + matrix[i][j]), (dp[i][j - 1] + matrix[i][j]));
            if (diagonals.count({ i, j }))
            {
                dp[i][j] = max(dp[i][j], (dp[i - 1][j - 1] + matrix[i][j]));
            }
        }
    }

    cout << dp[n - 1][n - 1];
}