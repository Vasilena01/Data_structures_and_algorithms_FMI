#pragma once
#include <iostream>
#include"SameTree.h"
using namespace std;

void dfsConversion(TreeNode* root, int& sum)
{
    if (!root)
        return;

    dfsConversion(root->right, sum);
    sum += root->val;
    root->val = sum;
    dfsConversion(root->left, sum);
}
TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    dfsConversion(root, sum);
    return root;
}