#pragma once
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int n = 0;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for (int num : nums)
            pq.push(num);
    }

    int add(int val) {
        pq.push(val);
        while (pq.size() > n)
            pq.pop();
        return pq.top();
    }
};