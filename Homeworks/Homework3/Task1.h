#pragma once
#include <iostream>
#include <list>
#include "SLL.h"
using namespace std;

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* headRes = nullptr;
    SinglyLinkedListNode* currRes = nullptr;

    if (head1 == nullptr)
        return head2;
    else if (head2 == nullptr)
        return head1;

    if (head1->data < head2->data)
    {
        headRes = head1;
        currRes = head1;
        head1 = head1->next;
    }
    else
    {
        headRes = head2;
        currRes = head2;
        head2 = head2->next;
    }

    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data < head2->data)
        {
            currRes->next = head1;
            head1 = head1->next;
        }
        else
        {
            currRes->next = head2;
            head2 = head2->next;
        }
        currRes = currRes->next;
    }

    if (head1 != nullptr)
    {
        currRes->next = head1;
    }
    else
    {
        currRes->next = head2;
    }

    return headRes;
}