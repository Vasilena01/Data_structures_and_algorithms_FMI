#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*Task 1*/
int isSymetricArray() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        stack<int> stack;
        for (int i = 0; i < n; i++)
        {
            if (!stack.empty() && nums[i] < 0 && stack.top() * -1 == nums[i])
            {
                stack.pop();
                continue;
            }
            stack.push(nums[i]);
        }

        if (stack.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

/*Task 2*/
struct Node
{
    int value;
    int index;
    vector<Node*> children;
    Node(int value, int index) : value(value), index(index) {}
};

Node* findNode(Node* root, int value)
{
    if (root->value == value)
        return root;

    for (int i = 0; i < root->children.size(); i++)
    {
        Node* found = findNode(root->children[i], value);
        if (found)
            return found;
    }

    return nullptr;
}

void countChildren(Node* root, vector<int>& res)
{
    if (!root)
        return;

    int count = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        countChildren(root->children[i], res);
        count += res[root->children[i]->index] + 1;
    }

    res[root->index] = count;
}

void kingdomTask()
{
    int n;
    cin >> n;
    vector<pair<int, int>> input(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> input[i].first >> input[i].second;

    // Creating the tree
    Node* root = new Node(input[0].first, 0);
    for (int i = 0; i < n - 1; i++)
    {
        Node* curr = findNode(root, input[i].first);
        Node* newNode = new Node(input[i].second, i + 1);
        curr->children.push_back(newNode);
    }

    // Counting each node's children
    vector<int> result(n);
    countChildren(root, result);

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
}