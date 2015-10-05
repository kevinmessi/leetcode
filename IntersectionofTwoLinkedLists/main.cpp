/*
 * A:           a1 → a2
 *                     ↘
 *                      c1 → c2 → c3
 *                     ↗
 * B:     b1 → b2 → b3
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA, *b = headB;
    int la = 0,lb = 0;
    while(a)
    {
        a = a->next;
        ++la;
    }
    while(b)
    {
        b = b->next;
        ++lb;
    }
    a = headA, b = headB;
    if(la > lb)
    {
        for(int i = 0;i < la - lb;++i)
        {
            a = a->next;
        }
    }
    else
    {
        for(int i = 0;i < lb - la;++i)
        {
            b = b->next;
        }
    }
    while(a != b)
    {
        a = a->next;
        b = b->next;
    }
    return a;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA, *b = headB;
    while(a != b)
    {
        if(a == NULL) a = headB;
        else a = a->next;
        if(b == NULL) b = headA;
        else b = b->next;
    }
    return a;
}

int main()
{
    ListNode *a = new ListNode(0);
    ListNode *b = new ListNode(0);
    ListNode *i = getIntersectionNode2(a,b);
    cout << i << endl;
    return 0;
}

