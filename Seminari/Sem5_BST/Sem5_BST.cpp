#include <iostream>
#include "BTPreorderTraversal.h"
#include "MaxDepthBT.h"
#include "BTLevelOrderTraversal.h"

int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);
	root->right = node1;
	root->right = node2;
	node2->right = node3;
	node2->right = node4;

	/*Task 1
	vector<int> res = preorderTraversal(root);
	for (int i = 0; i < res.size(); i++)
		cout << res[i];*/

	/*Task 2
	cout << getMaxDepth(root);*/

	/*Task 3*/
	vector<vector<int>> res = levelOrder(root);
	
}