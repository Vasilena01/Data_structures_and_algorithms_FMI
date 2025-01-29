#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

/*To solve:
    - exam 5 - 2022-2023 - task2
    - exam 5 - 2020-2021 exam 10 - task2 (T4 \/\/)
    - exam 7 - 2022-2023 task 1 and task 2 !!!
*/

/*T1 - check if there is a path between two nodes - for faster solution use static memory*/
void dfs(int curr, vector<int>& components, unordered_map<int, unordered_set<int>>& graph, int count)
{
    components[curr] = count;
    for (int neighbor : graph[curr])
    {
        if (!components[neighbor])
            dfs(neighbor, components, graph, count);
    }
}
void inpu1() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        graph[f - 1].insert(s - 1);
        graph[s - 1].insert(f - 1);
    }

    vector<int> components(v, 0);
    int count = 1;
    for (int i = 0; i < v; i++)
    {
        if (!components[i])
            dfs(i, components, graph, count);
        count++;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int f, s;
        cin >> f >> s;
        f--;
        s--;
        cout << (components[f] == components[s]) << " ";
    }
}

/*T2* - delete edges so every component to have even count of nodes*/
int dfs2(int curr, unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int& res)
{
    if (graph[curr].size() == 0)
        return 0;

    visited[curr] = true;
    int childrenCount = 1;
    for (int neighbor : graph[curr])
    {
        if (!visited[neighbor])
            childrenCount += dfs2(neighbor, graph, visited, res);
    }

    if (childrenCount % 2 == 0)
    {
        res++;
        return 0;
    }
    return childrenCount;
}
void input2() {
    unordered_map<int, unordered_set<int>> graph;
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        graph[f - 1].insert(s - 1);
        graph[s - 1].insert(f - 1);
    }

    vector<bool> visited(v);
    int res = 0;
    dfs2(1, graph, visited, res);
    cout << res - 1;
}

/*T3 - check if a given path is in graph*/
/*Solution1 - don't know why it works for only 1/10 testcases*/
bool bfs(int start, int end, unordered_set<int>& shouldNotVisit, unordered_map<int, unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == end)
            return true;

        if (visited.count(curr) || shouldNotVisit.count(curr))
            continue;

        visited.insert(curr);
        for (int neighbor : graph[curr])
        {
            if (!visited.count(neighbor))
                q.push(neighbor);
        }
    }
    return false;
}
void input3() {
    int v;
    cin >> v;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < v; i++)
    {
        int e;
        cin >> e;
        for (int j = 0; j < e; j++)
        {
            int el;
            cin >> el;
            graph[i].insert(el);
            graph[el].insert(i);
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int len;
        cin >> len;
        unordered_set<int> shouldNotVisit;
        vector<int> path;
        for (int j = 0; j < len; j++)
        {
            int el;
            cin >> el;
            path.push_back(el);
            shouldNotVisit.insert(el);
        }

        shouldNotVisit.erase(path[0]);
        bool exists = true;
        for (size_t j = 1; j < path.size(); j++)
        {
            shouldNotVisit.erase(path[j]);
            if (!bfs(path[j - 1], path[j], shouldNotVisit, graph))
            {
                exists = false;
                break;
            }
        }
        cout << exists << " ";
    }
}
/*Solution2 - working solution*/
void input4() {
    int v;
    cin >> v;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < v; i++)
    {
        int e;
        cin >> e;
        for (int j = 0; j < e; j++)
        {
            int el;
            cin >> el;
            graph[i].insert(el);
            graph[el].insert(i);
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int len;
        cin >> len;
        vector<int> path;
        for (int j = 0; j < len; j++)
        {
            int el;
            cin >> el;
            path.push_back(el);
        }

        bool exists = true;
        for (size_t j = 1; j < path.size(); j++)
        {
            if (!graph[path[j - 1]].count(path[j]))
            {
                exists = false;
                break;
            }
        }
        cout << exists << " ";
    }
}

/*T4* - get most occured path weight with exactly k edges*/
struct Edge
{
    int to, weight;
};
void dfs(int curr, int k, int currWeight, int depth, unordered_map<int, vector<Edge>>& graph, unordered_map<int, int>& weights, vector<bool>& visited)
{
    if (depth > k)
        return;

    if (depth == k)
    {
        weights[currWeight]++;
        return;
    }

    visited[curr] = true;
    for (auto edge : graph[curr])
    {
        if (!visited[edge.to])
        {
            dfs(edge.to, k, currWeight + edge.weight, depth + 1, graph, weights, visited);
        }
    }
    visited[curr] = false;
}
void input5() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < e; i++)
    {
        int f, s, c;
        cin >> f >> s >> c;
        graph[f--].push_back({ s--, c });
    }

    int k;
    cin >> k;
    //DFS for finding the weight of each path with k edges
    unordered_map<int, int> weights;
    for (int i = 0; i < v; i++)
    {
        vector<bool> visited(v, false);
        dfs(i, k, 0, 0, graph, weights, visited);
    }

    int maxWeight = -1, maxFreq = 0;
    for (const auto& weight : weights) {
        if (weight.second > maxFreq || (weight.second == maxFreq && weight.first > maxWeight)) {
            maxFreq = weight.second;
            maxWeight = weight.first;
        }
    }

    cout << maxWeight << endl;
}

/*T5 - check if its a cycle in graph*/
/*First solution - coloring*/
bool dfsCycle(int curr, unordered_map<int, unordered_map<int, int>>& graph, vector<int>& visited)
{
    visited[curr] = 1;
    for (auto neighbor : graph[curr])
    {
        if (visited[neighbor.first] == 2)
            continue;

        if (visited[neighbor.first] == 1)
            return true;

        if (dfsCycle(neighbor.first, graph, visited))
            return true;
    }
    return false;
}
void input5() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v, e;
        cin >> v >> e;
        unordered_map<int, unordered_map<int, int>> graph;
        for (int j = 0; j < e; j++)
        {
            int f, s, c;
            cin >> f >> s >> c;
            graph[f--].insert({ s--, c });
        }

        vector<int> visited(v, 0);
        bool isCycle = false;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j])
            {
                isCycle = dfsCycle(j, graph, visited);
                if (isCycle)
                    break;
            }
        }
        cout << isCycle;
    }
}
/*Second solution - having an inProgress array for the nodes which 
are not finished visiting*/
unordered_map <size_t, vector<size_t>> graph;
unordered_map<size_t, bool> visited;
bool hasCycle = false;
void dfs(size_t value, set<size_t>& values) {
    visited[value] = true;
    values.insert(value);

    for (const auto& element : graph[value]) {
        if (values.find(element) != values.end()) {
            hasCycle = true;
            return;
        }

        if (!visited[element]) {
            dfs(element, values);
        }
    }

    values.erase(value);
}
void input6() {
    
    size_t Q, N, E, start, end, weight;
    cin >> Q;

    for (size_t i = 0; i < Q; i++) {
        cin >> N >> E;
        hasCycle = false;
        for (size_t j = 0; j < N; ++j) {
            graph[j];
        }
        for (size_t j = 0; j < E; j++) {
            cin >> start >> end >> weight;
            graph[start].push_back(end);
        }

        set <size_t> values;
        for (const auto& element : graph) {
            if (!visited[element.first]) {
                dfs(element.first, values);
                if (hasCycle) {
                    break;
                }
            }
        }

        cout << hasCycle;
        graph.clear();
        visited.clear();
    }
}

/*T6 - Sueveriq return is given path valid, when its edge weights should appear 
in an arr with certain nums*/
void input7() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, vector<pair<int, int>>> graph;

    for (int i = 0; i < e; i++)
    {
        int f, s, c;
        cin >> f >> s >> c;
        graph[f].push_back({ s, c });
    }

    int k;
    cin >> k;
    unordered_set<int> specialWeights;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        specialWeights.insert(n);
    }

    int t;
    cin >> t;
    string result = "";
    for (int i = 0; i < t; i++)
    {
        int len;
        cin >> len;
        vector<int> path(len);
        for (int j = 0; j < len; j++)
            cin >> path[j];

        bool isValidPath = true;
        for (int j = 1; j < len; j++)
        {
            int start = path[j - 1];
            int end = path[j];
            bool isValidEdge = false;
            for (auto edge : graph[start])
            {
                if (edge.first == end && !specialWeights.count(edge.second))
                {
                    isValidEdge = true;
                    break;
                }
            }

            if (!isValidEdge)
            {
                isValidPath = false;
                break;
            }
        }
        result += (isValidPath ? '1' : '0');
    }
    cout << result;
}

/*T7 - check components count and cycle after adding edges with UnionFind*/
struct Edge2
{
    size_t v;
    size_t u;
};
Edge2 edges[1000002];
size_t parent[100002];
size_t depth[100002];
size_t findParent(size_t v)
{
    if (v == parent[v])
    {
        return v;
    }
    return findParent(parent[v]);
}
void unionV(size_t v, size_t u)
{
    //parent[findParent(v)] = findParent(u);
    int parentU = findParent(u);
    int parentV = findParent(v);

    if (parentU == parentV)
        return;

    if (depth[parentU] > depth[parentV])
        parent[parentV] = parentU;
    else if (depth[parentU] < depth[parentV])
        parent[parentU] = parentV;
    else
    {
        parent[parentV] = parentU;
        depth[parentU]++;
    }
}
void input8()
{
    size_t N, x, y, M = 0;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        parent[i] = i;
        depth[i] = 0;
    }
    while (cin >> x >> y)
    {
        edges[M] = { x, y };
        M++;
    }

    size_t components = N;
    for (size_t i = 0; i < M; i++)
    {
        size_t parentV = findParent(edges[i].v);
        size_t parentU = findParent(edges[i].u);
        if (parentV != parentU)
        {
            components--;
            cout << components << '\n';
            unionV(parentV, parentU);
            continue;
        }
        cout << components << " CYCLE FORMED!" << '\n';
    }
}

/*T8!!! - find given path len following the path sequence*/
int bfs(int start, int end, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& shouldNotVisit)
{
    queue<int> q;
    q.push(start);
    int sum = 0;

    while (!q.empty())
    {
        sum++;
        int levelSize = q.size();

        while (levelSize > 0)
        {
            int curr = q.front();
            q.pop();
            for (int neighbor : graph[curr])
            {
                if (neighbor == end)
                    return sum;
                if (!shouldNotVisit.count(neighbor))
                    q.push(neighbor);
            }
            levelSize--;
        }
    }
    return -1;
}
void input9() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        graph[f].insert(s);
    }

    int k;
    cin >> k;
    vector<int> path;
    unordered_set<int> shouldNotVisit;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        path.push_back(n);
        shouldNotVisit.insert(n);
    }

    shouldNotVisit.erase(path[0]);
    int sum = 0;
    for (int i = 1; i < k; i++)
    {
        shouldNotVisit.erase(path[i]);
        int result = bfs(path[i - 1], path[i], graph, shouldNotVisit);
        if (result == -1)
        {
            cout << -1;
            return;
        }
        sum += result;
    }
    cout << sum;
}