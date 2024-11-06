#pragma once
#include <iostream>

using namespace std;
class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
/*Task 1 - first solution*/
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    if (!llist)
        return newNode;

    if (llist->data >= data)
    {
        newNode->next = llist;
        llist = newNode;
        return llist;
    }

    DoublyLinkedListNode* curr = llist;
    while (curr)
    {
        if (curr->data >= data)
        {
            DoublyLinkedListNode* prev = curr->prev;
            prev->next = newNode;
            newNode->prev = prev;
            newNode->next = curr;
            curr->prev = newNode;
            return llist;
        }

        if (!curr->next)
            break;
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;

    return llist;
}
/*Task 1 - second solution
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* result = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* curr = llist;

    if (curr == nullptr)
        return result;

    if (curr->data >= data)
    {
        result->next = curr;
        llist = result;
        return llist;
    }

    //Finding the position where to insert data
    while (curr && curr->data < data)
    {
        //Going to the next data
        if (curr->next == nullptr)
            break;
        curr = curr->next;
    }

    if (curr->next == nullptr && curr->data < data)
    {
        curr->next = result;
        result->prev = curr;
    }
    else
    {
        //Inserting data
        DoublyLinkedListNode* prev = curr->prev;
        prev->next = result;
        result->prev = prev;
        result->next = curr;
    }

    return llist;
}*/

