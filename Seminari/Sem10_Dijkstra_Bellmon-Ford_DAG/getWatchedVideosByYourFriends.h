#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> bfs(vector<vector<int>>& friends, int id, int level) {
        vector<bool> visited(friends.size(), false);
        queue<pair<int, int>> q; // {current person, current level}
        vector<int> res;

        q.push({ id, 0 });
        visited[id] = true;

        while (!q.empty()) {
            auto [curr, currLevel] = q.front();
            q.pop();

            if (currLevel == level) {
                res.push_back(curr);
            }

            if (currLevel < level) {
                for (int neighbor : friends[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({ neighbor, currLevel + 1 });
                    }
                }
            }
        }
        return res;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends, int id,
        int level) {
        vector<int> friendIds = bfs(friends, id, level);
        unordered_map<string, int> videoFreq;

        for (int friendId : friendIds) {
            for (const string& video : watchedVideos[friendId]) {
                videoFreq[video]++;
            }
        }

        vector<pair<string, int>> videoList(videoFreq.begin(), videoFreq.end());

        sort(videoList.begin(), videoList.end(),
            [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second == b.second ? a.first < b.first
                    : a.second < b.second;
            });

        vector<string> result;
        for (const auto& [video, freq] : videoList) {
            result.push_back(video);
        }

        return result;
    }
};