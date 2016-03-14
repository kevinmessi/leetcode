#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

ListNode* oddEvenList(ListNode *head)
{
    if (!head) return head;
    ListNode *odd = head, *even = head->next, *even_head = even;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

