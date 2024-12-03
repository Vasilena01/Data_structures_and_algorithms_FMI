#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// First slow solution
vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
    int x) {
    unordered_map<int, vector<int>> map;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
        map[nums[i]].push_back(i);

    auto it = map.find(x);
    for (int i = 0; i < queries.size(); i++)
    {
        if (it == map.end())
        {
            res.push_back(-1);
            continue;
        }

        int count = queries[i];
        if (it->second.size() < count)
            res.push_back(-1);
        else
            res.push_back(it->second[count - 1]);
    }
    return res;
}

// Second fast solution
vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
    int x) {
    vector<int> occurrences;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x) {
            occurrences.push_back(i);
        }
    }

    for (int count : queries) {
        if (count > occurrences.size()) {
            res.push_back(-1);
        }
        else {
            res.push_back(occurrences[count - 1]);
        }
    }

    return res;
}