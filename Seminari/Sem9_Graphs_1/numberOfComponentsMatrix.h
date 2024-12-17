#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int curr, vector<vector<int>>& isConnected, vector<bool>& visited)
{
    visited[curr] = true;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (isConnected[curr][i] && curr != i && !visited[i])
            dfs(i, isConnected, visited);
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    int v = isConnected.size();
    vector<bool> visited(v);
    int count = 0;
    for (int i = 0; i < v; i++) {
        if (!visited[i])
        {
            dfs(i, isConnected, visited);
            count++;
        }
    }
    return count;
}