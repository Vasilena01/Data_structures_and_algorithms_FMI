#pragma once
#include <iostream>
#include <list>
#include "SLL.h"
using namespace std;

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* list, int data, int position) {
    SinglyLinkedListNode* currNode = list;
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (currNode == nullptr)
        return newNode;

    for (int i = 0; i < position - 1; i++)
    {
        currNode = currNode->next;
    }

    SinglyLinkedListNode* temp = currNode->next;
    currNode->next = newNode;
    newNode->next = temp;

    return list;
}