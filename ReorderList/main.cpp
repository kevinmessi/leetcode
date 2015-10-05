#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void PrintList(ListNode* head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void reorderList(ListNode* head)
{
    ListNode dummy(0);
    dummy.next = head;
    ListNode *slow = &dummy, *fast = &dummy;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *node = slow->next;
    while(node && node->next)
    {
        ListNode *temp = node->next->next;
        node->next->next = slow->next;
        slow->next = node->next;
        node->next = temp;
    }
    ListNode *half = slow->next;
    slow->next = NULL;
    while(half)
    {
        ListNode *temp = half->next;
        half->next = head->next;
        head->next = half;
        head = half->next;
        half = temp;
    }
}

int main()
{
    ListNode *list = new ListNode(0);
    ListNode *head = list;
    for(int i = 1;i < 5;++i)
    {
        head->next = new ListNode(i);
        head = head->next;
    }
    PrintList(list);
    reorderList(list);
    PrintList(list);
    return 0;
}
