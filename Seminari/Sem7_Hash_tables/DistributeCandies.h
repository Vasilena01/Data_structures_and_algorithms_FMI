#pragma once
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int distributeCandies(vector<int>& candyType) {
    unordered_set<int> uniqueTypes;
    size_t count = candyType.size() / 2;
    for (int i = 0; i < candyType.size(); i++)
        uniqueTypes.insert(candyType[i]);

    return std::min(uniqueTypes.size(), count);
}