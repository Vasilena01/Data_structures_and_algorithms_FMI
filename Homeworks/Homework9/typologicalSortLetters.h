#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void buildGraph(const vector<string>& strings, unordered_map<char, unordered_set<char>>& graph) {
    for (size_t i = 0; i < strings.size() - 1; i++) {
        const string& word1 = strings[i];
        const string& word2 = strings[i + 1];

        size_t minLength = min(word1.size(), word2.size());

        for (size_t j = 0; j < minLength; j++) {
            char char1 = word1[j];
            char char2 = word2[j];

            if (char1 != char2) {
                graph[char1].insert(char2);
                break;
            }
        }
    }
}
void topologicalSort(char curr, unordered_map<char, unordered_set<char>>& graph, unordered_set<char>& visited, vector<char>& stack)
{
    visited.insert(curr);
    for (char neighbor : graph[curr])
    {
        if (!visited.count(neighbor))
            topologicalSort(neighbor, graph, visited, stack);
    }
    stack.push_back(curr);
}
int getInput() {
    int n;
    cin >> n;
    vector<string> strings(n);

    cin.ignore();

    /*for (int i = 0; i < n; i++) {
        getline(cin, strings[i]);
    }*/

    unordered_map<char, unordered_set<char>> graph;
    vector<char> stack;
    unordered_set<char> visited;

    buildGraph(strings, graph);
    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        char ch = it->first;
        if (!visited.count(ch))
        {
            topologicalSort(ch, graph, visited, stack);
        }
    }
    std::reverse(stack.begin(), stack.end());
    for (char ch : stack)
        cout << ch << " ";
}