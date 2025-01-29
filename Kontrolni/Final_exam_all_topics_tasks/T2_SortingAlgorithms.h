#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*T1 - get unique symbols indicies in str*/
void countingSort(string& s)
{
    vector<int> count(256);
    vector<int> res;
    for (size_t i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        count[ch]++;
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        if (count[s[i]] == 1)
            res.push_back(i);
    }

    for (int i : res)
        cout << i << " ";
}

void input1() {
    string s;
    cin >> s;

    countingSort(s);
}

/*T2 - get indicies of elements in sorted arr*/
void input2() {
    int n;
    cin >> n;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> n;
        pairs.push_back({ n, i });
    }

    vector<int> res(n);
    sort(pairs.begin(), pairs.end());

    for (size_t i = 0; i < pairs.size(); i++)
    {
        res[pairs[i].second] = i;
    }

    for (int i : res)
        cout << i << " ";
}