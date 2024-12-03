#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;

        if (dp.count(root))
            return dp[root];

        int rob = root->val;
        if (root->left)
            rob += dfs(root->left->left) + dfs(root->left->right);

        if (root->right)
            rob += dfs(root->right->left) + dfs(root->right->right);

        int notrob = dfs(root->left) + dfs(root->right);

        dp[root] = max(rob, notrob);
        return dp[root];
    }
    int rob(TreeNode* root) {
        return dfs(root);
    }
};