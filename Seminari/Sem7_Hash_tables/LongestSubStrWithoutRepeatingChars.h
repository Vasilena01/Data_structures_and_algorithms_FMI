#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Almost correct solution
int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int currCount = 0;
    int maxCount = 0;

    for (char ch : s)
    {
        if (set.find(ch) != set.end())
        {
            currCount = set.size();
            auto it = set.begin();
            while (it != set.end() && *it != ch)
                it = set.erase(it);

            if (it != set.end() && *it == ch)
                set.erase(it);
        }
        set.insert(ch);
        maxCount = max(maxCount, currCount);
    }
    return maxCount;
}

// Second correct solution
int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int currCount = 0;
    int maxCount = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++)
    {
        char curr = s[right];
        while (set.find(curr) != set.end())
        {
            set.erase(s[left]);
            left++;
        }
        set.insert(curr);
        currCount = right - left + 1;
        maxCount = max(maxCount, currCount);
    }
    return maxCount;
}

