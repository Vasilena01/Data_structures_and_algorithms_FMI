#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/*T1 - stickers*/
void input1() {
    int n;
    cin >> n;
    vector<int> s1(n);
    vector<int> s2(n);
    unordered_map<int, int> istickers;
    for (int i = 0; i < n; i++)
    {
        cin >> s1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> s2[i];
    }

    int daysCount = 0;
    for (int i = 0; i < n; i++)
    {
        istickers[s1[i]]++;
        int target = s2[i];

        if (istickers[target] > 0)
        {
            istickers[target]--;
            continue;
        }

        daysCount++;
    }
    cout << daysCount;
}

/*T2 - get components count with vcount % k == 0*/
void dfs(int curr, unordered_map<int, unordered_set<int>>& graph,
    vector<bool>& visited, int& count)
{
    visited[curr] = true;
    count++;
    for (int neighbor : graph[curr])
    {
        if (!visited[neighbor])
            dfs(neighbor, graph, visited, count);
    }
}
void input2()
{
    int v, e, k;
    cin >> v >> e >> k;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    vector<bool> visited(v);
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        int currCount = 0;
        if (!visited[i])
        {
            dfs(i, graph, visited, currCount);
            if (currCount % k == 0)
                count++;
        }
    }
    cout << count;
}

/*T4 - get certain path without visiting certain nodes*/
int bfs(int start, int end, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& shouldNotVisit)
{
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    int len = 0;

    while (!q.empty())
    {
        int levellen = q.size();

        while (levellen > 0)
        {
            int curr = q.front();
            q.pop();

            if (curr == end)
                return len;

            visited.insert(curr);
            for (int neighbor : graph[curr])
            {
                if (!visited.count(neighbor) && !shouldNotVisit.count(neighbor))
                {
                    q.push(neighbor);
                }
            }
            levellen--;
        }
        len++;
    }
    return 0;
}
void input4()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    int p;
    cin >> p;
    vector<int> path;
    unordered_set<int> shouldNotVisit;
    for (int i = 0; i < p; i++)
    {
        int x;
        cin >> x;
        path.push_back(x);
        shouldNotVisit.insert(x);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int y;
        cin >> y;
        shouldNotVisit.insert(y);
    }

    shouldNotVisit.erase(path[0]);
    int resPath = 0;
    for (int i = 1; i < path.size(); i++)
    {
        shouldNotVisit.erase(path[i]);
        resPath += bfs(path[i - 1], path[i], graph, shouldNotVisit);
    }
    cout << resPath;
}