#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/*T1 - asteroid colision*/
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> stack;
    for (int i = 0; i < asteroids.size(); i++)
    {
        int curr = asteroids[i];
        bool isDestroyed = false;

        while (!stack.empty() && curr < 0 && stack.top() > 0)
        {
            if (abs(curr) == abs(stack.top()))
            {
                stack.pop();
                isDestroyed = true;
                break;
            }
            else if (abs(curr) > abs(stack.top()))
            {
                stack.pop();
            }
            else
            {
                isDestroyed = true;
                break;
            }
        }

        if (!isDestroyed)
            stack.push(curr);
    }

    vector<int> res;
    while (!stack.empty())
    {
        res.push_back(stack.top());
        stack.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

/*T2 - is symetric arr*/
void isSymetric()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i++)
            cin >> arr[i];

        stack<int> stack;
        for (int num : arr)
        {
            if (num < 0 && !stack.empty())
            {
                int curr = stack.top();
                if (curr == abs(num))
                    stack.pop();
                continue;
            }
            stack.push(num);
        }
        if (stack.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
