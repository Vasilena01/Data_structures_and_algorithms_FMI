#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        int other = target - curr;
        if (map.find(other) != map.end())
            return { map[other], i };

        map[curr] = i;
    }
    return {};
}
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        int target = -curr;

        vector<int> indicies = twoSum(nums, target);
        if (indicies.size() && i != indicies[0] && i != indicies[1] &&
            indicies[0] != indicies[1]) {
            vector<int> triplet = { nums[indicies[0]], nums[indicies[1]],
                                   curr };
            sort(triplet.begin(), triplet.end());
            uniqueTriplets.insert(triplet);
        }
    }
    vector<vector<int>> res(uniqueTriplets.begin(), uniqueTriplets.end());
    return res;
}