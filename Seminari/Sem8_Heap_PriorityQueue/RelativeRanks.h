#pragma once
#include <iostream>
#include <queue>
#include <string>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    vector<string> answer(score.size());
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < score.size(); i++)
        pq.push({ score[i], i });

    int count = 1;
    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        if (count == 1)
            answer[curr.second] = "Gold Medal";
        else if (count == 2)
            answer[curr.second] = "Silver Medal";
        else if (count == 3)
            answer[curr.second] = "Bronze Medal";
        else
            answer[curr.second] = to_string(count);
        count++;
    }
    return answer;
}