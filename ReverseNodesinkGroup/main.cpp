#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

ListNode* reverseKGroup(ListNode *head, int k)
{
    ListNode dummy(0);
    ListNode *node = head;
    head = &dummy;
    while (node)
    {
        ListNode *tail = node;
        int j;
        for (j = 0; j < k && node; ++j)
        {
            ListNode *temp = node->next;
            node->next = head->next;
            head->next = node;
            node = temp;
        }
        if (j != k)
        {
            node = head->next;
            head->next = NULL;
            while (node)
            {
                ListNode *temp = node->next;
                node->next = head->next;
                head->next = node;
                node = temp;
            }
        }
        head = tail;
    }
    return dummy.next;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
