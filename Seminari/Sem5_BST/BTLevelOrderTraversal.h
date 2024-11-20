#pragma once
#include "BTPreorderTraversal.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root)
        return {};

    vector<vector<int>> res;
    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty())
    {
        vector<int> currLevel;
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* curr = queue.front();
            currLevel.push_back(curr->val);
            queue.pop();

            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }
        res.push_back(currLevel);
    }
    return res;
}