#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    deque<int> sizes;

    for (int i = 0; i < asteroids.size(); i++)
    {
        int curr = asteroids[i];
        while (!sizes.empty() && curr < 0
            && sizes.back() > 0)
        {
            // If the intelect of the curr person is < than the last added in deque
            if (abs(curr) < sizes.back())
            {
                // curr loses
                curr = 0;
                break;
            }
            // If the intelect of the curr person is = to the last added in deque 
            else if (abs(curr) == sizes.back())
            {
                // both lose
                curr = 0;
                sizes.pop_back();
                break;
            }
            // While the curr person intelect is > that the last from deque
            else
            {
                // curr wins
                sizes.pop_back();
            }
        }

        if (curr != 0)
            sizes.push_back(curr);
    }

    int size = sizes.size();
    vector<int> res(size);
    for (int i = 0; i < size; i++)
    {
        res[i] = sizes.front();
        sizes.pop_front();
        if (sizes.empty())
            break;
    }

    return res;
}