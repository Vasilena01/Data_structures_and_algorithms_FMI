#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node_second
{
	Node_second* left;
	Node_second* right;
	int data;
};

bool isCurrBST(Node_second* root, int minVal, int maxVal)
{
	if (!root)
		return true;

	if (root->data <= minVal || root->data >= maxVal)
		return false;

	return isCurrBST(root->left, minVal, root->data) &&
		isCurrBST(root->right, root->data, maxVal);
}

void isBST()
{
	int t;
	cin >> t;
	vector<int> results(t);
	for (int j = 0; j < t; j++)
	{
		int n;
		cin >> n;
		vector<Node_second> nodes(n);

		for (int i = 0; i < n; i++)
		{
			int value, leftIndx, rightIndx;
			cin >> value >> leftIndx >> rightIndx;

			nodes[i].left = leftIndx == -1 ? nullptr : &nodes[leftIndx];
			nodes[i].right = rightIndx == -1 ? nullptr : &nodes[rightIndx];
			nodes[i].data = value;
		}

		results[j] = isCurrBST(&nodes[0], INT_MIN, INT_MAX) ? 1 : 0;
	}

	for (int i = 0; i < t; i++)
		cout << results[i] << endl;
}