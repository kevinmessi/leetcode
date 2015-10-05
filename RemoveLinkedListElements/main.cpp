#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void PrintListNode(ListNode* head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* removeElements(ListNode* head, int val)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *tmp;
    while(head)
    {
        if(head->val == val)
        {
            pre->next = head->next;
            tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            pre = head;
            head = head->next;
        }
    }
    head = dummy->next;
    delete dummy;
    return head;
}

ListNode* removeElements2(ListNode* head, int val)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *tmp;
    while(head)
    {
        if(head->val != val)
        {
            pre->next = head;
            pre = head;
            head = head->next;
        }
        else
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    pre->next = NULL;
    head = dummy->next;
    delete dummy;
    return head;
}


int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node = head;
    for(int i = 2;i < 5 && node;++i)
    {
        node->next = new ListNode(2);
        node = node->next;
    }
    node->next = new ListNode(4);
    PrintListNode(head);
    PrintListNode(removeElements2(head, 2));
    return 0;
}
