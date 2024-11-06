#pragma once
#include <iostream>
#include <list>
#include "SLL.h"
using namespace std;

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* list) {
    SinglyLinkedListNode* resHead = nullptr;
    SinglyLinkedListNode* resCurr = nullptr;

    if (list == nullptr)
        return resHead;
    else
    {
        resCurr = list;
        resHead = resCurr;
    }


    while (list != nullptr)
    {
        list = list->next;

        if (list != nullptr && resCurr->data != list->data)
        {
            resCurr->next = list;
            resCurr = resCurr->next;
        }
    }

    resCurr->next = nullptr;
    return resHead;
}