#include <iostream>
#include <vector>

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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *list = new ListNode(0);
    list->next = head;
    ListNode *slow = list, *fast = list;
    while(n >= 0)
    {
        fast = fast->next;
        --n;
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    head = list->next;
    delete list;
    return head;
}

//ListNode *removeNthFromEnd(ListNode *head, int n)
//{
//    vector<ListNode*> list;
//    ListNode *node = head;
//    while(node)
//    {
//        list.push_back(node);
//        node = node->next;
//    }
//    int target = list.size() - n;
//    if(target == 0) head = head->next;
//    else if(n == 1) list[target-1]->next = NULL;
//    else list[target-1]->next = list[target+1];
//    delete list[target];
//    return head;
//}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *list = head;
    for(int i = 1;i < 6;++i)
    {
        list->next = new ListNode(i);
        list = list->next;
    }
    PrintList(head);
    PrintList(removeNthFromEnd(head, 1));
    return 0;
}

