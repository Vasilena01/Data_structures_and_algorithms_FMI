#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
        set.insert(nums[i]);

    if (set.size() == 1)
        return 1;

    for (auto it = set.begin(); it != set.end(); it++)
    {
        int curr = *it;
        if (set.find(curr - 1) == set.end())
        {
            int currNum = curr;
            int currCount = 1;

            while (set.find(currNum + 1) != set.end())
            {
                currNum++;
                currCount++;
            }

            count = max(count, currCount);
        }
    }
    return count;
}