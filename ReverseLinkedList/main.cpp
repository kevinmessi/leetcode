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

ListNode* reverseList2(ListNode* head)
{
    ListNode *list = NULL;
    ListNode *node;
    while(head)
    {
        node = head;
        head = head->next;
        node->next = list;
        list = node;
    }
    return list;
}

ListNode* reverseList(ListNode* head)
{
    ListNode *list = head;
    if(head && head->next)
    {
        list = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
    }
    return list;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node = head;
    for(int i = 2;i < 30 && node;++i)
    {
        node->next = new ListNode(i);
        node = node->next;
    }
    PrintListNode(head);
    PrintListNode(reverseList2(head));
    return 0;
}

