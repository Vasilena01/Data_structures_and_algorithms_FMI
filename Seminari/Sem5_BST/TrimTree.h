#pragma once
#include <iostream>
#include"SameTree.h"
using namespace std;

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root)
        return nullptr;

    if (root->val < low)
    {
        root->right = trimBST(root->right, low, high);
        return root->right;
    }
    else if (root->val > high)
    {
        root->left = trimBST(root->left, low, high);
        return root->left;
    }
    else
    {
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
    }
    return root;
}