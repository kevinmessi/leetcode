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

void deleteNode(ListNode* node)
{
    ListNode *temp = node->next;
    *node = *temp;
    delete temp;
}

int main()
{
    ListNode head = ListNode(0);
    ListNode *node = &head;
    for(int i = 1;i < 10;i++)
    {
        //        ListNode temp = ListNode(i);
        //        node->next = &temp;
        ListNode *temp = new ListNode(i);
        node->next = temp;
        node = temp;
    }
    PrintList(&head);
    return 0;
}

