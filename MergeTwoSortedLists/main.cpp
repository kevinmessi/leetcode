/*
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *list = new ListNode(0);
    ListNode *head = list;
    while(true)
    {
        if(l2 == NULL)
        {
            list->next = l1;
            break;
        }
        if(l1 == NULL)
        {
            list->next = l2;
            break;
        }
        if(l1->val < l2->val)
        {
            list->next = l1;
            l1 = l1->next;
        }
        else
        {
            list->next = l2;
            l2 = l2->next;
        }
        list = list->next;
    }
    ListNode *sorted_list = head->next;
    delete head;
    head = NULL;
    return sorted_list;
}

ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0);
    ListNode *list = head;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            list->next = l1;
            l1 = l1->next;
        }
        else
        {
            list->next = l2;
            l2 = l2->next;
        }
        list = list->next;
    }
    list->next = l1 ? l1:l2;
    list = head->next;
    delete head;
    head = NULL;
    return list;
}

int main()
{
    ListNode *node = new ListNode(1);
    cout << node->val << endl;
    return 0;
}

