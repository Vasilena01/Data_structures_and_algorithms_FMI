#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*Task 1*/
struct Node2
{
	int val;
	Node2* left = nullptr;
	Node2* right = nullptr;
	Node2(int val) : val(val) {}
};

Node2* insert(Node2* root, int val)
{
	if (root == nullptr)
		return new Node2(val);

	if (val < root->val)
		root->left = insert(root->left, val);
	else if (val > root->val)
		root->right = insert(root->right, val);
	return root;
}

void dfs(Node2* root, vector<int>& res)
{
	if (!root)
		return;

	if (root->left && root->right)
		res.push_back(root->val);

	if (root->left)
		dfs(root->left, res);

	if (root->right)
		dfs(root->right, res);
}

void specialPrintingBST()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, val;
		cin >> n >> val;
		Node2* root = new Node2(val);
		for (int i = 0; i < n - 1; i++)
		{
			cin >> val;
			insert(root, val);
		}
		
		vector<int> res;
		dfs(root, res);
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
}