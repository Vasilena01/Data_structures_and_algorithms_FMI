#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <stack>
using namespace std;

/*T1 - get unique matrix rows*/
void input1() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> elements(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            elements[i][j] = num;
        }
    }

    map<vector<int>, int> rowsOccur;
    for (int i = 0; i < n; i++)
        rowsOccur[elements[i]]++;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (rowsOccur[elements[i]] == 1)
            count++;
    }

    cout << count;
}

/*T2 - find shortest path - bfs and dijkstra*/
void bfs(int start, vector<int>& distances, unordered_map<int, unordered_set<int>>& graph)
{
    queue<int> q;
    unordered_set<int> visited;
    distances[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            int curr = q.front();
            q.pop();

            visited.insert(curr);
            for (int neighbor : graph[curr])
            {
                if (!visited.count(neighbor))
                {
                    distances[neighbor] = distances[curr] + 6;
                    q.push(neighbor);
                }
            }
        }
    }
}
void input2() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        unordered_map<int, unordered_set<int>> graph;
        int v, e;
        cin >> v >> e;
        for (int j = 0; j < e; j++)
        {
            int f, s;
            cin >> f >> s;
            graph[f - 1].insert(s - 1);
            graph[s - 1].insert(f - 1);
        }

        int start;
        cin >> start;
        start--;
        vector<int> distances(v, -1);
        bfs(start, distances, graph);
        for (size_t j = 0; j < distances.size(); j++)
        {
            if (distances[j] == 0)
                continue;
            cout << distances[j] << " ";
        }
        cout << endl;
    }
}
/*Dijkstra solution*/
struct Edge
{
    int to;
    int weight;
};
struct Node1
{
    int index, cost;
    bool operator<(const Node1& other) const
    {
        return cost > other.cost;
    }
};
void dijkstra(int start, vector<int>& distances, unordered_map<int, vector<Edge>>& graph)
{
    priority_queue<Node1> pq;
    pq.push({ start, 0 });
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if (curr.cost > distances[curr.index])
            continue;

        for (auto neighbor : graph[curr.index])
        {
            int newWeight = curr.cost + neighbor.weight;
            if (newWeight < distances[neighbor.to])
            {
                distances[neighbor.to] = newWeight;
                pq.push({ neighbor.to, newWeight });
            }
        }
    }
}
void input2D() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        unordered_map<int, vector<Edge>> graph;
        int v, e;
        cin >> v >> e;
        for (int j = 0; j < e; j++)
        {
            int f, s;
            cin >> f >> s;
            graph[f - 1].push_back({ s - 1, 6 });
            graph[s - 1].push_back({ f - 1, 6 });
        }

        int start;
        cin >> start;
        start--;
        vector<int> distances(v, INT_MAX);
        dijkstra(start, distances, graph);
        for (size_t j = 0; j < distances.size(); j++)
        {
            if (j == start)
                continue;
            if (distances[j] == INT_MAX)
            {
                cout << -1 << " ";
                continue;
            }
            cout << distances[j] << " ";
        }
        cout << endl;
    }
}

/*T3 - sum 2 nums of the form of a linked list*/
struct Node {
    Node* next;
    int data;
};
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void solve(LinkedList& num2) {
        Node* head1 = head;
        Node* head2 = num2.head;

        stack<int> res;
        int rest = 0;
        while (head1 && head2)
        {
            int v1 = head1->data;
            int v2 = head2->data;
            int resVal = v1 + v2 + rest;
            rest = resVal % 10;
            int digit = resVal / 10;
            res.push(digit);
            head1 = head1->next;
            head2 = head2->next;
        }

        while (head1)
        {
            int v1 = head1->data;
            int resVal = v1 + rest;
            rest = resVal % 10;
            int digit = resVal / 10;
            res.push(digit);
            head1 = head1->next;
        }

        while (head2)
        {
            int v2 = head2->data;
            int resVal = v2 + rest;
            rest = resVal % 10;
            int digit = resVal / 10;
            res.push(digit);
            head2 = head2->next;
        }

        if (rest)
            res.push(rest);

        while (!res.empty())
        {
            cout << res.top();
            res.pop();
        }
    }

private:
    Node* head, * tail;
};

/*T4 - pancakes*/
int minSeconds = 0;
bool check(vector<int>& chefs, int seconds, int target)
{
    int pancakesCount = 0;
    for (int el : chefs)
    {
        pancakesCount += seconds / el;
        if (pancakesCount >= target)
            return true;
    }
    return false;
}
void binarySearch(vector<int>& chefs, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (check(chefs, mid, target))
        {
            right = mid - 1;
            minSeconds = mid;
        }
        else
            left = mid + 1;
    }
}
void input4() {
    int n, k;
    cin >> k >> n;
    vector<int> chefs(n);
    for (int i = 0; i < n; i++)
        cin >> chefs[i];

    sort(chefs.begin(), chefs.end());
    binarySearch(chefs, chefs[0], chefs[0] * k, k);
    cout << minSeconds;
}

/*T5 - get sum of children verticies*/
void dfs(int curr, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int& sum)
{
    visited.insert(curr);
    for (int neighbor : graph[curr])
    {
        if (!visited.count(neighbor))
        {
            sum += neighbor + 1;
            dfs(neighbor, graph, visited, sum);
        }
    }
}
void input5() {
    int e, k;
    cin >> e >> k;
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        graph[f - 1].insert(s - 1);
    }

    for (int i = 0; i < k; i++)
    {
        int start;
        cin >> start;
        unordered_set<int> visited;
        int sum = 0;
        start--;
        dfs(start, graph, visited, sum);
        cout << sum << endl;
    }
}