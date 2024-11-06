#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*First slow solution
ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;

    ListNode* prev = head;
    ListNode* curr = prev->next;
    int countMoves = 0;

    while (prev != nullptr && curr != nullptr)
    {
        while (curr->next != nullptr && prev->val > curr->val
            && prev->val > curr->next->val)
        {
            curr = curr->next;
            countMoves++;
        }

        if (countMoves == 0)
        {
            // If prev < curr - no need to swap
            prev = curr;
            curr = curr->next;
        }
        else
        {
            // If prev > some number after curr - need to swap
            ListNode* temp = prev;
            prev = prev->next;
            ListNode* currNext = curr->next;
            curr->next = temp;
            temp->next = currNext;
            curr = prev->next;
        }
    }

    return head;
}*/
/*Second fast solution*/
ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* lastSorted = head;
    ListNode* curr = head->next;

    while (curr)
    {
        if (lastSorted->val <= curr->val)
            lastSorted = lastSorted->next;
        else
        {
            // Finding the position before the prev value where to insert current
            ListNode* prev = &dummy;

            while (prev->next->val <= curr->val)
                prev = prev->next;

            // Inserting current between first min before curr and prev->next
            ListNode* currNext = curr->next;
            lastSorted->next = currNext;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = lastSorted->next;
    }
    return dummy.next;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}