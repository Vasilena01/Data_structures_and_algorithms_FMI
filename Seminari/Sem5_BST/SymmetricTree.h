#pragma once
#include <iostream>
#include"SameTree.h"
using namespace std;

bool checkForSymetry(TreeNode* leftNode, TreeNode* rightNode)
{
    if (!leftNode && !rightNode)
        return true;

    if (!leftNode || !rightNode)
        return false;

    if (leftNode->val != rightNode->val)
        return false;

    return checkForSymetry(leftNode->left, rightNode->right) &&
        checkForSymetry(leftNode->right, rightNode->left);
}
bool isSymmetric(TreeNode* root) {
    return checkForSymetry(root->left, root->right);
}

