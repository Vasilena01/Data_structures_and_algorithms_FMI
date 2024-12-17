#pragma once
#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<int> degree(n, 0);

    for (auto it : edges)
    {
        int start = it[0] - 1;
        int end = it[1] - 1;
        degree[end]++;
        degree[start]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (degree[i] > 1)
            return i + 1;
    }
    return -1;
}