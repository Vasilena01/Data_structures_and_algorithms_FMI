#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	pair<int, int> data;
};

void sumColums(Node* root, vector<long>& resultsArr, int offset)
{
	if (!root)
		return;

	resultsArr[root->data.second + offset] += root->data.first;
	sumColums(root->left, resultsArr, offset);
	sumColums(root->right, resultsArr, offset);
}

void getPeopleCountPerSlope()
{
	int n;
	cin >> n;
	vector<Node> nodes(n);
	int minIndex = 0, maxIndex = 0;

	for (int i = 0; i < n; i++)
	{
		int value, leftIndx, rightIndx;
		cin >> value >> leftIndx >> rightIndx;

		nodes[i].left = leftIndx == -1 ? nullptr : &nodes[leftIndx];
		nodes[i].right = rightIndx == -1 ? nullptr : &nodes[rightIndx];
		nodes[i].data.first = value;

		if (i == 0)
			nodes[i].data.second = 0;

		if (nodes[i].left)
		{
			nodes[leftIndx].data.second = nodes[i].data.second - 1;
			minIndex = min(minIndex, nodes[leftIndx].data.second);
		}

		if (nodes[i].right)
		{
			nodes[rightIndx].data.second = nodes[i].data.second + 1;
			maxIndex = max(maxIndex, nodes[rightIndx].data.second);
		}
	}

	int offset = -minIndex;
	vector<long> resultsArr(maxIndex - minIndex + 1, 0);

	sumColums(&nodes[0], resultsArr, offset);
	for (long sum : resultsArr) {
		if (sum != 0) {
			cout << sum << " ";
		}
	}
}