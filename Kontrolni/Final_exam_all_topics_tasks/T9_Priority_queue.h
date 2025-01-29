#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/*T1 - balance papaq tree - each weight to be at least >= s*/
void papaq()
{
    int n, s;
    cin >> n >> s;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int count = 0;
    while (pq.top() < s && pq.size() >= 2)
    {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int toInsert = f + 2 * s;
        pq.push(toInsert);
        count++;
    }

    if (pq.size() == 1 && pq.top() < s)
        cout << -1;
    else
        cout << count;
}

/*T2 - get median of num stream*/
double getMedian(priority_queue<int>& left, priority_queue<int, vector<int>, greater<int>>& right, int el)
{
    if (left.empty() && right.empty())
    {
        left.push(el);
    }
    else if (!right.empty() && el > right.top())
    {
        right.push(el);
    }
    else
        left.push(el);

    // Balance the heaps so they have at least 1 el differance in their sizes
    if (left.size() > right.size() + 1)
    {
        right.push(left.top());
        left.pop();
    }
    else if (right.size() > left.size())
    {
        left.push(right.top());
        right.pop();
    }

    if (left.size() == right.size())
        return (left.top() + right.top()) / 2.0;
    else
        return left.top() / 1.0;
}
void inpu2() {
    int n;
    cin >> n;
    priority_queue<int> maxHeapL;
    priority_queue<int, vector<int>, greater<int>> minHeapR;
    //cout << fixed << setprecision(1);
    int num;
    while (cin >> num)
    {
        cout << double(getMedian(maxHeapL, minHeapR, num)) << endl;
    }
}

/*T3 - get max overlapping intervals*/
/*First solution - with time error*/
void getCountOfOverlapping(pair<int, int>& compare, priority_queue<pair<int, int>> pq, int& count)
{
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        if (curr.first < compare.second && curr.second > compare.first)
            count++;
    }
}
void getTimes() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        pq.push({ f, s });
    }

    int maxCount = 1;
    while (!pq.empty())
    {
        int count = 1;
        auto curr = pq.top();
        pq.pop();
        getCountOfOverlapping(curr, pq, count);
        if (count > maxCount)
            maxCount = count;
    }

    cout << maxCount;
}
/*Second solution - without time error*/
void getTimes2()
{
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        times.push_back({ f, 1 });
        times.push_back({ s, -1 });
    }

    sort(times.begin(), times.end(), [](pair<int, int>& f, pair<int, int>& s) {
        if (f.first == s.first) return f.second < s.second;
        return f.first < s.first;
        });

    int count = 0;
    int maxCount = 0;
    for (auto curr : times)
    {
        count += curr.second;
        maxCount = max(count, maxCount);
    }
    cout << maxCount;
}

/*T4 - exam 4 - task 1 from 2021-2022 to be solved*/
