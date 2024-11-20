#pragma once
#include <iostream>
using namespace std;

class MyCalendar {
public:
    struct Node {
        pair<int, int> data;
        Node* left;
        Node* right;
        Node(int start, int end) : data({ start, end }), left(nullptr),
            right(nullptr) {}
    };

    Node* root;

    MyCalendar() { root = nullptr; }

    bool insert(Node* root, int startTime, int endTime) {
        if (endTime <= root->data.first)
        {
            if (!root->left)
            {
                root->left = new Node(startTime, endTime);
                return true;
            }
            return insert(root->left, startTime, endTime);
        }
        else if (startTime >= root->data.second)
        {
            if (!root->right)
            {
                root->right = new Node(startTime, endTime);
                return true;
            }
            return insert(root->right, startTime, endTime);
        }
        else
            return false;
    }

    bool book(int startTime, int endTime) {
        if (!root)
        {
            root = new Node(startTime, endTime);
            return true;
        }
        return insert(root, startTime, endTime);
    }
};