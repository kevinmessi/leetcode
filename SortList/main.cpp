#include "../toolkit/data_structure.h"
#include <iostream>

using namespace std;

ListNode* sortList(ListNode* head)
{
    if (!head || !head->next) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *one = dummy;
    ListNode *two = dummy;
    while (two && two->next)
    {
        one = one->next;
        two = two->next->next;
    }
    two = one->next;
    one->next = NULL;
    one = head;
    one = sortList(one);
    two = sortList(two);
    head = dummy;
    while (one && two)
    {
        if (one->val <= two->val)
        {
            head->next = one;
            one = one->next;
        }
        else
        {
            head->next = two;
            two = two->next;
        }
        head = head->next;
    }
    head->next = one ? one : two;
    head = dummy->next;
    delete dummy;
    return head;
}

int count_size(ListNode *node)
{
    int n = 0;
    while (node != NULL)
    {
        node = node->next;
        ++n;
    }
    return n;
}

ListNode *sortList2(ListNode *head)
{
    int len = count_size(head);
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    for (int block_size = 1; block_size < len; block_size <<= 1)
    {
        ListNode *last = dummy, *it = dummy->next;
        int a = 0, b = 0;
        for (int cursor = 0; cursor < len; cursor += a + b)
        {
            ListNode *A = it, *B = NULL;
            a = min(len - cursor, block_size);
            b = min(len - cursor - a, block_size);
            if (b != 0)
            {
                for (int i = 0; i < a - 1; ++i) it = it->next;
                B = it->next;
                it->next = NULL;
                it = B;
                for (int i = 0; i < b - 1; ++i) it = it->next;
                ListNode *tmp = it->next;
                it->next = NULL;
                it = tmp;
            }
            while (A || B)
            {
                if (B == NULL || (A != NULL && A->val <= B->val))
                {
                    last->next = A;
                    A = A->next;
                }
                else
                {
                    last->next = B;
                    B = B->next;
                }
                last = last->next;
            }
        }
    }
    head = dummy->next;
    delete dummy;
    dummy = NULL;
    return head;
}

int main()
{
    sortList2(NULL);
    cout << "Hello World!" << endl;
    return 0;
}
