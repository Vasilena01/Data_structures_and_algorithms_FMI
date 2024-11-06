#pragma once
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

/*struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void push_back(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    Node* newHead = nullptr;
    Node* kTail = nullptr;

    while (curr != nullptr)
    {
        Node* groupHead = curr;
        Node* prev = nullptr;

        int count = 0;

        while (count < k && curr)
        {
            count++;
            curr = curr->next;
        }

        if (count == k)
        {
            curr = groupHead;
            Node* nextNode = nullptr;

            for (int i = 0; i < k; i++)
            {
                nextNode = curr->next;
                curr->next = curr->prev;
                curr->prev = nextNode;
                prev = curr;
                curr = nextNode;
            }
        }

        if (newHead == nullptr)
            newHead = prev;

        if (kTail != nullptr)
            kTail->next = curr;

        if (curr != nullptr)
            curr->next = groupHead;

        kTail = groupHead;
    }

    return newHead ? newHead : head;
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}*/
