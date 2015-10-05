#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *s = new ListNode(0);
    ListNode *sum = s;
    int v = 0;
    while (l1 != NULL || l2 != NULL || v >= 1)
    {
        if(l1 != NULL)
        {
            v += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            v += l2->val;
            l2 = l2->next;
        }
        s->next = new ListNode(v % 10);
        s = s->next;
        v /= 10;
    }
    ListNode *tmp = sum;
    sum = sum->next;
    delete tmp;
    tmp = NULL;
    return sum;
}

int main()
{
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(6);
    cout << addTwoNumbers(l1, l2)->next->val << endl;
    return 0;
}

