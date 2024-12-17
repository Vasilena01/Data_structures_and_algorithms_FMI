#pragma once
#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustedBySomeone(n + 1, 0);
    vector<int> trustsSomeone(n + 1, 0);

    for (const auto& t : trust)
    {
        int a = t[0];
        int b = t[1];
        trustsSomeone[a]++;
        trustedBySomeone[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (trustedBySomeone[i] == n - 1 && trustsSomeone[i] == 0)
            return i;
    }
    return -1;
}