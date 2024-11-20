#pragma once
#include "BTPreorderTraversal.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> rightSideView(TreeNode* root) {
    if (!root)
        return {};

    vector<int> res;
    queue<TreeNode*> levels;
    levels.push(root);

    while (!levels.empty())
    {
        int lastElementFromLevel = 0;
        int size = levels.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* curr = levels.front();
            if (i == size - 1)
                lastElementFromLevel = curr->val;
            levels.pop();

            if (curr->left)
                levels.push(curr->left);
            if (curr->right)
                levels.push(curr->right);
        }

        res.push_back(lastElementFromLevel);
    }
    return res;
}