#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void PrintList(ListNode *head)
{
    ListNode *node = head;
    while(node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* swapPairs(ListNode* head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *pre = dummy;
    ListNode *node = head;
    while(node && node->next)
    {
        pre->next = node->next;
        node->next = node->next->next;
        pre->next->next = node;
        pre = node;
        node = node->next;
    }
    head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *list = head;
    list->next = new ListNode(2);
    list = list->next;
    list->next = new ListNode(3);
    list = list->next;
    list->next = new ListNode(4);
    list = list->next;
    PrintList(head);
    PrintList(swapPairs(head));
    return 0;
}

