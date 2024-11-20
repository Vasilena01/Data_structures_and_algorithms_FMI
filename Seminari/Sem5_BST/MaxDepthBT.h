#pragma once
#include "BTPreorderTraversal.h"
#include <iostream>
#include <vector>
using namespace std;

void maxDepthRec(TreeNode* root, int& max, int curr)
{
    while (root)
    {
        curr++;
        if (root->left)
            maxDepthRec(root->left, max, curr);
        if (root->right)
            maxDepthRec(root->right, max, curr);

        if (max < curr)
            max = curr;
        return;
    }
}

int getMaxDepth(TreeNode* root)
{
    int max = 0;
    int curr = 0;
    maxDepthRec(root, max, curr);
    return max;
}