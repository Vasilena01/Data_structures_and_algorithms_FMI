#pragma once
#include <iostream>

using namespace std;
struct Node
{
    int value;
    Node* next;
    // Constructor with two arguments, one of which is default
    Node(int value, Node* next = nullptr) : value(value), next(next) {};
};

/*Correct solution*/
void replace(Node* head, Node* tail, int size, int X)
{
    Node* curr = head;

    while (curr) {
        if (curr->value == X) {
            curr->value = 1;
            for (int i = 0; i < X - 1; i++) {
                Node* newNode = new Node(1);
                Node* temp = curr->next;
                curr->next = newNode;
                newNode->next = temp;
                if (curr == tail) {
                    tail = newNode;
                }
                size++;
            }
        }

        curr = curr->next;
    }
}
/*My solution*/
void replace(Node* head, int X){
    if (head == nullptr)
        return;

    Node* prev = nullptr;
    Node* curr = head;

    while (curr && curr->value == X)
    {
        Node* firstNode = new Node(1);
        Node* temp = firstNode;

        for (int i = 1; i < X; i++)
        {
            Node* newNode = new Node(1);
            temp->next = newNode;
            temp = newNode;
        }

        temp->next = curr->next;

        if (curr == head)
        {
            head = firstNode;
        }
        else
        {
            prev->next = firstNode;
        }

        prev = temp;
        curr = temp->next;
    }


    while (curr)
    {
        if (curr->value == X)
        {
            Node* firstNode = new Node(1);
            Node* temp = firstNode;
            for (int i = 1; i < X; i++)
            {
                Node* newNode = new Node(1);
                temp->next = newNode;
                temp = newNode;
            }
            temp->next = curr->next;
            prev->next = firstNode;
            curr = temp->next;
            prev = temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

/*Task 2 - replace second edition*/
void replace(Node* head, int X)
{
    Node* curr = head;
    if (!curr)
        return;

    int position = 0;
    int num;
    while (curr)
    {
        if (position == X)
            num = curr->value;
        curr = curr->next;
        position++;
    }

    curr = head;
    while (curr)
    {
        if (curr->next == nullptr)
            break;

        if (curr->value == num)
            curr->value = curr->next->value;
        curr = curr->next;
    }
}