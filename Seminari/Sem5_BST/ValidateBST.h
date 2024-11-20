#pragma once
#include "BTPreorderTraversal.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(TreeNode* root, long min, long max)
{
    if (!root)
        return true;

    if (root->val <= min || root->val >= max)
        return false;

    return dfs(root->left, min, root->val) &&
        dfs(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
}