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

/*Task 1 - remove all occurences of certain num from the linked list*/
void removeAll(Node* head, Node* tail, int X)
{
    if (!head)
        return;
    if (head == tail)
    {
        if (head->value == X)
        {
            head = tail = nullptr;
        }
        else
            return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr)
    {
        if (curr->value == X)
        {
            if (prev == nullptr)
            {
                Node* temp = curr;
                curr = curr->next;
                head = curr;
                delete temp;
            }
            else
            {
                Node* temp = curr;
                curr = curr->next;
                prev->next = curr;
                delete temp;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

/*Task 3 - group elements - 1/2 it works*/
void group(Node* head, int size, int start, int end)
{
    if (!head)
        return;

    if (start > size || start > end)
    {
        std::cout << "fail_grouping";
        return;
    }

    Node* curr = head;
    Node* startNode = nullptr;
    Node* endNode = nullptr;
    int count = 0;
    int sum = 0;

    if (start == 0)
    {
        while (curr && count <= end)
        {
            sum += curr->value;
            curr = curr->next;
            count++;
        }

        if (count > end)
        {
            endNode = curr;
            Node* newNode = new Node(sum);
            head = newNode;
            head->next = endNode;
            return;
        }
        else
        {
            // In case end > size
            std::cout << "fail_grouping";
            return;
        }
    }

    while (curr)
    {
        if (count == start - 1)
        {
            startNode = curr;
            count++;
        }

        if (count == start)
        {
            sum += curr->value;
            count++;
            curr = curr->next;

            while (curr && count <= end)
            {
                sum += curr->value;
                curr = curr->next;
                count++;
            }
        }

        if (count == end + 1)
        {
            endNode = curr;
            break;
        }

        curr = curr->next;
        count++;
    }

    if (count < start || count < end)
    {
        std::cout << "fail_grouping";
        return;
    }

    Node* newNode = new Node(sum);
    startNode->next = newNode;
    newNode->next = endNode;

}