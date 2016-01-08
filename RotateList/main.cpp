#include "../toolkit/data_structure.h"
#include <iostream>

using namespace std;

ListNode* rotateRight(ListNode* head, int k)
{
    if (head == NULL) return NULL;
    ListNode *node = head;
    int len = 1;
    while (node->next)
    {
        ++len;
        node = node->next;
    }
    k %= len;
    node->next = head;
    for (int i = 0; i < len - k; ++i)
    {
        node = node->next;
    }
    head = node->next;
    node->next = NULL;
    return head;
}

int main()
{
    rotateRight(NULL, 0);
    return 0;
}

