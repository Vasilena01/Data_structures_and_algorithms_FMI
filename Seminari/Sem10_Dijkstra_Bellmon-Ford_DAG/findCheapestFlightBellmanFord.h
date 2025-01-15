#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    struct Edge {
        int from;
        int to;
        int weight;
    };

    int bellman_ford(int start, int end, int k, int n, vector<Edge>& edges)
    {
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int> currIteration(distances);
            for (auto edge : edges)
            {
                if (distances[edge.from] != INT_MAX)
                {
                    currIteration[edge.to] = min(currIteration[edge.to], distances[edge.from] + edge.weight);
                }
            }
            distances = std::move(currIteration);
        }

        if (distances[end] == INT_MAX)
            return -1;
        return distances[end];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<Edge> edges;
        for (auto flight : flights)
            edges.push_back({ flight[0], flight[1], flight[2] });

        return bellman_ford(src, dst, k, n, edges);
    }
};