#pragma once
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> paths(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        if (obstacleGrid[0][i] == 1)
        {
            paths[0][i] = 0;
            break;
        }
        else
            paths[0][i] = 1;
    }

    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1)
        {
            paths[i][0] = 0;
            break;
        }
        else
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