#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if(head == NULL) return NULL;
    ListNode *node = head->next;
    ListNode *pre = head;
    int v = pre->val;
    while (node)
    {
        if(v == node->val)
        {
            pre->next = node->next;
            ListNode *tmp = node;
            node = node->next;
            delete tmp;
            tmp = NULL;
        }
        else
        {
            pre = node;
            v = pre->val;
            node = node->next;
        }
    }
    return head;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

