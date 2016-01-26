#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

ListNode* deleteDuplicates1(ListNode* head)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    bool duplicate;
    int v;
    while (head)
    {
        if (head->next && head->val == head->next->val)
        {
            duplicate = true;
            v = head->val;
            head = head->next->next;
            pre->next = head;
        }
        else
        {
            if (duplicate && head->val == v)
            {
                pre->next = head->next;
            }
            else
            {
                duplicate = false;
                pre = head;
            }
            head = head->next;
        }
    }
    return dummy.next;
}

ListNode* deleteDuplicates2(ListNode* head)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy, *temp;
    bool duplicate;
    int v;
    while (head)
    {
        if (head->next && head->val == head->next->val)
        {
            duplicate = true;
            v = head->val;
            temp = head;
            head = head->next;
            delete temp;
            temp = head;
            head = head->next;
            delete temp;
            pre->next = head;
        }
        else
        {
            if (duplicate && head->val == v)
            {
                pre->next = head->next;
                temp = head;
                head = head->next;
                delete temp;
            }
            else
            {
                duplicate = false;
                pre = head;
                head = head->next;
            }
        }
    }
    return dummy.next;
}

ListNode* deleteDuplicates3(ListNode* head)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;
    while (head)
    {
        if (head->next && head->val == head->next->val)
        {
            while (head->next && head->val == head->next->val)
            {
                ListNode *temp = head;
                head = head->next;
                delete temp;
            }
            ListNode *temp = head;
            head = head->next;
            delete temp;
            pre->next = head;
        }
        else
        {
            pre = head;
            head = head->next;
        }
    }
    return dummy.next;
}

ListNode* deleteDuplicates4(ListNode* head)
{
    ListNode **runner = &head;
    while (*runner)
    {
        if ((*runner)->next && (*runner)->val == (*runner)->next->val)
        {
            ListNode *node = *runner;
            while (node && (*runner)->val == node->val)
            {
                node = node->next;
            }
            *runner = node;
        }
        else
        {
            runner = &((*runner)->next);
        }
    }
    return head;
}

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode **runner = &head;
    while (*runner)
    {
        if ((*runner)->next && (*runner)->val == (*runner)->next->val)
        {
            int v = (*runner)->val;
            ListNode *node = *runner;
            while (node && v == node->val)
            {
                ListNode *temp = node;
                node = node->next;
                delete temp;
            }
            *runner = node;
        }
        else
        {
            runner = &((*runner)->next);
        }
    }
    return head;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

