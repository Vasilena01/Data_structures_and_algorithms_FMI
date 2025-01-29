#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/*T1 - print right side view tree*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
vector<int> rightSideView(TreeNode* root) {
    if (!root)
        return {};

    queue<TreeNode*> levels;
    levels.push(root);

    vector<int> res;
    while (!levels.empty())
    {
        int size = levels.size();
        int lastElementFromLevel = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode* curr = levels.front();
            if (i == size - 1)
                lastElementFromLevel = curr->val;

            levels.pop();

            if (curr->left)
                levels.push(curr->left);
            if (curr->right)
                levels.push(curr->right);
        }

        res.push_back(lastElementFromLevel);
    }
    return res;
}

/*T2 - isValid bst*/
bool dfs(TreeNode* curr, long min, long max)
{
    if (!curr)
        return true;

    if (curr->val <= min || curr->val >= max)
        return false;

    return dfs(curr->left, min, curr->val) &&
        dfs(curr->right, curr->val, max);
}
bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_MIN, LONG_MAX);
}

/*T3* - count of children of each node in the bst*/
struct Node
{
    int childrenCount = 0;
    vector<int> children;
};
void dfs(vector<Node>& nodes, int index)
{
    for (auto& child : nodes[index].children) {
        dfs(nodes, child);
        nodes[index].childrenCount += nodes[child].childrenCount + 1;
    }
}
void input() {
    int n;
    cin >> n;
    int first, second;
    vector<Node> nodes(n);

    while (cin >> first >> second)
    {
        nodes[first].children.push_back(second);
    }
    dfs(nodes, 0);
    for (int i = 0; i < n; i++)
        cout << nodes[i].childrenCount << " ";
}

/*T4 - print nodes with only two children in bst*/
struct Node4
{
    Node4* left = nullptr;
    Node4* right = nullptr;
    int val;
    Node4(int val) : val(val) {};
};
Node4* insert(Node4* root, int val)
{
    if (!root)
        return new Node4(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void dfs4(Node4* root, vector<int>& res)
{
    if (!root)
        return;

    if (root->left && root->right)
        res.push_back(root->val);

    if (root->left)
        dfs4(root->left, res);
    if (root->right)
        dfs4(root->right, res);
}
int input4() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int first;
        cin >> first;
        Node4* root = new Node4(first);
        for (int j = 0; j < n - 1; j++)
        {
            int val;
            cin >> val;
            root = insert(root, val);
        }

        vector<int> res;
        dfs4(root, res);
        for (int num : res)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}

/*T5 - print nodes that are only seen from above*/
Node4* insert(Node4* curr, int val)
{
    if (!curr)
        return new Node4(val);

    if (val < curr->val)
        curr->left = insert(curr->left, val);

    if (val > curr->val)
        curr->right = insert(curr->right, val);

    return curr;
}
void input5() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int val;
        cin >> val;
        Node4* root = new Node4(val);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            root = insert(root, val);
        }

        queue<pair<Node4*, int>> nodes;
        nodes.push({ root, 0 });
        stack<Node4*> leftTree;
        queue<Node4*> rightTree;
        int leftCount = 0;
        int rightCount = 0;

        while (!nodes.empty())
        {
            auto curr = nodes.front();
            nodes.pop();
            int currColumn = curr.second;

            if (currColumn < 0 && abs(currColumn) > leftCount)
            {
                leftCount++;
                leftTree.push(curr.first);
            }

            if (currColumn > 0 && currColumn > rightCount)
            {
                rightCount++;
                rightTree.push(curr.first);
            }

            if (curr.first->left)
            {
                nodes.push({ curr.first->left, currColumn - 1 });
            }

            if (curr.first->right)
            {
                nodes.push({ curr.first->right, currColumn + 1 });
            }
        }

        while (!leftTree.empty())
        {
            Node4* curr = leftTree.top();
            leftTree.pop();
            cout << curr->val << " ";
        }
        cout << root->val << " ";
        while (!rightTree.empty())
        {
            Node4* curr = rightTree.front();
            rightTree.pop();
            cout << curr->val << " ";
        }
        cout << endl;
    }
}

/*T6 - get sum of all odd leaves*/
void dfs(Node4* curr, int& sum)
{
    if (!curr)
        return;

    if (!curr->left && !curr->right)
    {
        if (curr->val % 2 != 0)
        {
            sum += curr->val;
            return;
        }
    }

    dfs(curr->left, sum);
    dfs(curr->right, sum);
}
void leaves(Node4* root) {
    int sum = 0;
    dfs(root, sum);
    cout << sum;
}

/*T7 - bfs print levels from left to right, from right to left*/
void printSFB(Node4* root) {
    queue<Node4*> levels;
    levels.push(root);
    bool leftToRight = false;
    while (!levels.empty())
    {
        int size = levels.size();
        vector<int> res;
        while (size > 0)
        {
            Node4* curr = levels.front();
            levels.pop();
            if (curr->left)
                levels.push(curr->left);
            if (curr->right)
                levels.push(curr->right);
            res.push_back(curr->val);
            size--;
        }
        if (leftToRight)
            reverse(res.begin(), res.end());

        for (int n : res)
            cout << n << " ";
        leftToRight = !leftToRight;
    }
}

/*T8 - delete nodes with only one generation of children*/
bool hasChildren(Node4* root) {
    return root->left != NULL || root->right != NULL;
}
void printSorted(Node4* root) {
    if (root == NULL)
        return;

    printSorted(root->left);
    cout << root->val << " ";
    printSorted(root->right);
}
Node4* deleteChildrenLeaves(Node4* root) {
    if (root == NULL || (root->right == NULL && root->left == NULL)) {
        return root;
    }
    if (root->left == NULL) {
        if (!hasChildren(root->right)) {
            Node4* temp = root->right;
            delete root;
            root = temp;
            return root;
        }
        root->right = deleteChildrenLeaves(root->right);
    }
    else if (root->right == NULL) {
        if (!hasChildren(root->left)) {
            Node4* temp = root->left;
            delete root;
            root = temp;
            return root;
        }
        root->left = deleteChildrenLeaves(root->left);
    }
    else {
        if (!hasChildren(root->left) && !hasChildren(root->right)) {
            root->right->left = root->left;
            Node4* temp = root->right;
            delete root;
            root = temp;
            return root;
        }
        root->right = deleteChildrenLeaves(root->right);
        root->left = deleteChildrenLeaves(root->left);
    }

    return root;
}