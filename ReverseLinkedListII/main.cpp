#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

ListNode* reverseBetween1(ListNode* head, int m, int n)
{
    ListNode dummy(0);
    dummy.next = head;
    head = &dummy;
    for (int i = 1; i < m; ++i)
        head = head->next;
    ListNode *node = head->next, *list = NULL;
    for (int i = m; i <= n; ++i)
    {
        ListNode *temp = node;
        node = node->next;
        temp->next = list;
        list = temp;
    }
    head->next->next = node;;
    head->next = list;
    return dummy.next;
}

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    ListNode dummy(0);
    dummy.next = head;
    head = &dummy;
    for (int i = 1; i < m; ++i)
        head = head->next;
    ListNode *node = head->next;
    for (int i = m; i < n; ++i)
    {
        ListNode *temp = node->next;
        node->next = temp->next;
        temp->next = head->next;
        head->next = temp;
    }
    return dummy.next;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

