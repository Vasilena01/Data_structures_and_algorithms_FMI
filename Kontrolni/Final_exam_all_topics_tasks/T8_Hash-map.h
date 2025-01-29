#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

/*T1 - return if the second sentence is created from the words from the first one*/
void input1()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long s1, s2;
        cin >> s1 >> s2;
        unordered_map<string, long long> sent1;
        unordered_map<string, long long> sent2;

        for (long long i = 0; i < s1; i++)
        {
            string s;
            cin >> s;
            sent1[s]++;
        }

        for (long long i = 0; i < s2; i++)
        {
            string s;
            cin >> s;
            sent2[s]++;
        }

        bool contains = true;
        for (auto el : sent2)
        {
            string s = el.first;
            long long value = el.second;
            if ((sent1.find(s) == sent1.end()) || sent1[s] < value)
            {
                contains = false;
                break;
            }
        }
        contains ? cout << "Yes" : cout << "No" << endl;
    }
}

/*T2 - print words which are unique for the sentence they belong to and 
    dont appear in the other sentence*/
void input2() {
    unordered_map<string, int> s1;
    unordered_map<string, int> s2;

    string s;
    while (cin >> s)
    {
        s1[s]++;
    }

    while (cin >> s)
    {
        s2[s]++;
    }

    vector<string> res;
    for (auto word : s1)
    {
        string w = word.first;
        int count = word.second;
        if (count > 1 || s2.find(w) != s2.end())
            continue;
        res.push_back(w);
    }

    for (auto word : s2)
    {
        string w = word.first;
        int count = word.second;
        if (count > 1 || s1.find(w) != s1.end())
            continue;
        res.push_back(w);
    }

    sort(res.begin(), res.end());
    for (string word : res)
        cout << word << endl;
}

/*T3* - put nonUnique nums at the end as they've occured in the first arr and 
leave the unique ones at their first positions - print the result (2018-2019 task1 exam7)*/
void input3() {
    unordered_map <size_t, size_t> peopleMap;
    unordered_map<size_t, bool> added;
    size_t N;
    cin >> N;
    vector<int> arr(N);
    for (size_t i = 0; i < N; ++i) {
        cin >> arr[i];
        peopleMap[arr[i]]++;
    }

    queue <size_t> order;
    vector <size_t> result;

    for (size_t i = 0; i < N; i++)
    {
        if (peopleMap[arr[i]] == 1)
            result.push_back(arr[i]);
        else if (added.find(arr[i]) == added.end())
        {
            added[arr[i]] = true;
            order.push(i);
        }
    }

    while (!order.empty()) {
        result.push_back(arr[order.front()]);
        order.pop();
    }

    for (int n : result)
        cout << n << " ";
}

