#include "Task1.h"
#include "Task4.h"
#include "Task5.h"
#include "InsertionSortLL.h"

#pragma warning (disable:4996)

int main()
{
	/*Task 1
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;*/

    /*Task 4 - reverse linked list for k els - first solution
    int n;
    cin >> n;
    list<int> nums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int k;
    cin >> k;

    if (k <= 1 || k > n)
    {
        for (const int& node : nums)
            cout << node << " ";
        return 0;
    }

    auto itBegin = nums.begin();

    while (itBegin != nums.end())
    {
        auto itEnd = itBegin;

        for (int i = 0; i < k && itEnd != nums.end(); i++)
            itEnd++;

        if (std::distance(itBegin, itEnd) == k) {
            std::reverse(itBegin, itEnd);
        }

        for (int i = 0; i < k && itBegin != nums.end(); i++)
            itBegin++;
    }

    for (const int& node : nums)
        cout << node << " ";*/

    /*Task 4 - reverse linked list for k els - second solution
    int N, k;
    std::cin >> N;
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        push_back(head, tail, value);
    }

    std::cin >> k;

    head = reverseKGroup(head, k);
    printList(head);

    return 0;*/

    /*Task 5 - npm install
    long long t, n;
    cin >> t >> n;
    vector<long long> nums(t);
    for (long long i = 0; i < t; i++)
        cin >> nums[i];

    getNpmPackages(nums, t, n);*/

    /*Insertion sort linked list*/
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    
    std::cout << "Original list: ";
    printList(head);
    
    // Sort the list
    head = insertionSortList(head);
    
    std::cout << "Sorted list: ";
    printList(head);
}