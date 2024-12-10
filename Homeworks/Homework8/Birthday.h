#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    priority_queue<int, vector<int>, greater<>> availableChairs;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeChairs;

    for (int i = 0; i < times.size(); i++)
    {
        minHeap.push({ times[i][0], i });
        availableChairs.push(i);
    }

    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        minHeap.pop();

        int arrival = curr.first;
        int friendIndx = curr.second;

        while (!freeChairs.empty() && freeChairs.top().first <= arrival)
        {
            int chair = freeChairs.top().second;
            freeChairs.pop();
            availableChairs.push(chair);
        }

        if (!availableChairs.empty())
        {
            int chair = availableChairs.top();
            availableChairs.pop();
            freeChairs.push({ times[friendIndx][1], chair });

            if (targetFriend == friendIndx)
                return chair;
        }
    }
    return -1;
}