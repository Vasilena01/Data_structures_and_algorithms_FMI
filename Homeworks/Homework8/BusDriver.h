#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool canGetAll() {
    int n, c;
    cin >> n >> c;
    vector<pair<pair<int, int>, int>> peopleAndTimes;

    for (int i = 0; i < n; i++) {
        int k, start, end;
        cin >> k >> start >> end;
        peopleAndTimes.push_back({ {start, end}, k });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    sort(peopleAndTimes.begin(), peopleAndTimes.end(),
        [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            return a.first.first < b.first.first;
        });

    int currentPassengers = 0;
    for (auto personInLine : peopleAndTimes) {
        int groupSize = personInLine.second;
        int arrivalTime = personInLine.first.first;
        int departureTime = personInLine.first.second;

        while (!pq.empty() && pq.top().first <= arrivalTime) {
            currentPassengers -= pq.top().second;
            pq.pop();
        }

        if (currentPassengers + groupSize > c) {
            return false;
        }

        pq.push({ departureTime, groupSize });
        currentPassengers += groupSize;
    }

    return true;
}