//Given a linked list and a value x, partition it such that
//all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

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
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* Array2List(int a[], int n)
{
    if(n <= 0) return NULL;
    ListNode *head = new ListNode(a[0]);
    ListNode *node = head;
    for(int i = 1;i < n;++i)
    {
        node->next = new ListNode(a[i]);
        node = node->next;
    }
    return head;
}

ListNode* partition(ListNode *head, int x)
{
    ListNode *dummy_s = new ListNode(0);
    ListNode *dummy_b = new ListNode(0);
    ListNode *node_s = dummy_s;
    ListNode *node_b = dummy_b;
    ListNode *node = head;
    while(node)
    {
        if(node->val < x)
        {
            node_s->next = new ListNode(node->val);
            node_s = node_s->next;
        }
        else
        {
            node_b->next = new ListNode(node->val);
            node_b = node_b->next;
        }
        node = node->next;
    }
    node_s->next = dummy_b->next;
    ListNode *phead = dummy_s->next;
    delete dummy_s;
    delete dummy_b;
    return phead;
}

int main()
{
    int a[] = {1, 4, 3, 2, 5, 2};
    ListNode *head = Array2List(a, 6);
    PrintList(head);
    ListNode *phead = partition(head, 3);
    PrintList(phead);
    return 0;
}

