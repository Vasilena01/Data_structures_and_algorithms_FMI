#pragma once
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string toBinaryString(int num, size_t length) {
    string binaryStr;
    while (num > 0) {
        binaryStr =
            (char)('0' + (num % 2)) + binaryStr;
        num /= 2;
    }

    while (binaryStr.size() < length) {
        binaryStr = '0' + binaryStr;
    }

    return binaryStr;
}
string findDifferentBinaryString(vector<string>& nums) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++)
        set.insert(stoi(nums[i], nullptr, 2));

    for (int i = 0; i < 1 << nums.size(); i++)
    {
        if (set.find(i) == set.end())
            return toBinaryString(i, nums.size());
    }
    return toBinaryString(-1, nums.size());
}