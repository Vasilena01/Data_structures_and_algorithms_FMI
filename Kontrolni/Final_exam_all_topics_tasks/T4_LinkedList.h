#pragma once
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*T1 - remove Nth element from back in LL*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int getSize(ListNode* head)
{
    ListNode* curr = head;
    int count = 0;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || !head->next)
        return nullptr;

    int size = getSize(head);
    int currPosition = 0;
    ListNode* curr = head;
    ListNode* prev = nullptr;

    if (size - n == 0)
    {
        head = head->next;
        return head;
    }
    if (size == 2 && n == 1)
    {
        head->next = nullptr;
        return head;
    }

    while (curr)
    {

        if (size - n == currPosition)
        {
            curr = curr->next;
            prev->next = curr;
            break;
        }

        prev = curr;
        curr = curr->next;
        currPosition++;
    }
    return head;
}

/*T2 - insert new value in a sorted LL*/
ListNode* sortedInsert(ListNode* llist, int data) {
    ListNode* newNode = new ListNode(data);

    if (!llist) {
        return newNode;
    }

    if (llist->val >= data) {
        newNode->next = llist;
        llist->prev = newNode;
        return newNode;
    }

    ListNode* curr = llist;

    while (curr->next && curr->next->val < data) {
        curr = curr->next;
    }

    // If inserting at the tail
    if (!curr->next) {
        curr->next = newNode;
        newNode->prev = curr;
    }
    else {
        // Insert between `curr` and `curr->next`
        ListNode* nextNode = curr->next;
        curr->next = newNode;
        newNode->next = nextNode;
    }

    return llist;
}