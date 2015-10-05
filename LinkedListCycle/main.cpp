#include "linkedlist.h"

#include <iostream>

using namespace std;

bool hasCycle(ListNode *head)
{
    ListNode *one=head;
    ListNode *two=head;
    while(two && two->next)
    {
        one=one->next;
        two=two->next->next;
        if(one==two) return true;
    }
    return false;
}

int main()
{
    cout << "hasCycle(list)" << endl;
    return 0;
}

