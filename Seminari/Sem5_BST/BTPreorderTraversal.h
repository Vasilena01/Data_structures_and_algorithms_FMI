#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void preorderTraversalRec(TreeNode* root, vector<int>& res) {
	while (root)
	{
		res.push_back(root->val);
		if (root->left)
			preorderTraversalRec(root->left, res);
		if (root->right)
			preorderTraversalRec(root->right, res);
		return;
	}
}

vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> res;
	preorderTraversalRec(root, res);
	return res;
}
