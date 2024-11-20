#pragma once
#include <iostream>
#include"SameTree.h"
using namespace std;

void getSum(TreeNode* root, int low, int high, int& sum)
{
    if (!root)
        return;

    if (root->val >= low && root->val <= high)
        sum += root->val;

    getSum(root->left, low, high, sum);
    getSum(root->right, low, high, sum);
}
int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    getSum(root, low, high, sum);
    return sum;
}