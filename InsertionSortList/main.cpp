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

ListNode* insertionSortList(ListNode* head)
{
    if(head == NULL) return NULL;
    ListNode *dummy = new ListNode(INT_MIN);
    dummy->next = head;
    ListNode *last = head;
    ListNode *node = head->next;
    while(node)
    {
        if(node->val < last->val)
        {
            ListNode *pre = dummy;
            while(true)
            {
                if(node->val < pre->next->val) break;
                else pre = pre->next;
            }
            last->next = node->next;
            node->next = pre->next;
            pre->next = node;
        }
        else last = node;
        node = last->next;
    }
    head = dummy->next;
    delete dummy;
    return head;
}

int main()
{
    ListNode *head = new ListNode(2);
    ListNode *list = head;
    list->next = new ListNode(1);
    list = list->next;
    list->next = new ListNode(5);
    list = list->next;
    list->next = new ListNode(7);
    list = list->next;
    list->next = new ListNode(3);
    PrintList(head);
    PrintList(insertionSortList(head));
    return 0;
}

