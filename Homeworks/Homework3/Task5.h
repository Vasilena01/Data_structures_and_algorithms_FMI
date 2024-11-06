#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long data;
    Node* next;
    Node* prev;
    Node(long long val) : data(val), next(nullptr), prev(nullptr) {}
};

void push_back(Node*& head, Node*& tail, long long data) {
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

void pop_front(Node*& head)
{
    if (!head)
        return;
    else
    {
        Node* temp = head;
        head = head->next;
        if(head)
            head->prev = nullptr;
        delete temp;
    }
}

void send_back(Node*& head, Node*& tail, long long num)
{
    Node* curr = head;
    if (head == tail)
        return;
    else
    {
        while (curr != nullptr)
        {
            if (curr->data == num)
            {
                // Sending the current element to the back

                if (curr == tail)
                {
                    return;
                }
                
                if (curr == head)
                {
                    head = curr->next;
                    head->prev = nullptr;
                }
                else
                {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                tail->next = curr;
                curr->prev = tail;
                curr->next = nullptr;
                tail = curr;

                return;
            }
            curr = curr->next;
        }
    }
}

bool isNumInList(Node*& head, Node*& tail, long long num)
{
    Node* curr = head;

    if (head == nullptr || tail == nullptr)
        return false;
    else
    {
        while (curr != nullptr)
        {
            if (curr->data == num)
                return true;
            curr = curr->next;
        }
    }
    return false;
}

void getNpmPackages(vector<long long>& nums, long long size, long long maxCount)
{
    Node* head = nullptr;
    Node* tail = nullptr;
    long long listSize = 0;

	for (long long i = 0; i < size; i++)
	{
        // If num is not in the linked list - push_back and pop_front
        if (!isNumInList(head, tail, nums[i]))
        {
            push_back(head, tail, nums[i]);
            listSize++;

            if (listSize > maxCount)
                pop_front(head);
            cout << "false" << std::endl;
        }
        // If num is already in the linked list - send it back
        else
        {
            send_back(head, tail, nums[i]);
            cout << "true" << std::endl;
        }
	}
}