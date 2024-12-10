#pragma once
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    MedianFinder() {

    }

    void addNum(int num) {
        if (minHeap.size() == 0 || num > minHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);

        if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size())
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else
            return minHeap.size() > maxHeap.size() ? minHeap.top() :
            maxHeap.top();
    }
};