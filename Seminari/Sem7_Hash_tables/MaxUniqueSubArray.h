#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> set;
    int res = 0;
    int currSum = 0;
    int start = 0;

    for (int end = 0; end < nums.size(); end++)
    {
        int curr = nums[end];

        while (set.find(curr) != set.end())
        {
            set.erase(nums[start]);
            currSum -= nums[start];
            start++;
        }
        set.insert(curr);
        currSum += curr;
        res = max(res, currSum);
    }
    return res;
}