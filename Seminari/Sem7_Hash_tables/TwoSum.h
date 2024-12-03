#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// First non optimal solution
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> map;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
        map[nums[i]].push_back(i);

    for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i];
        int searched = target - curr;
        auto it = map.find(searched);
        if (it != map.end()) {
            if (curr == searched && it->second.size() == 1)
                continue;
            res.push_back(i);
            if (curr == searched && it->second.size() > 1)
                res.push_back(it->second[1]);
            else
                res.push_back(it->second[0]);
            break;
        }
    }
    return res;
}

// Second optimal solution
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr = nums[i];
        int other = target - curr;
        if (map.find(other) != map.end())
            return { map[other], i };

        map[curr] = i;
    }
    return {};
}
