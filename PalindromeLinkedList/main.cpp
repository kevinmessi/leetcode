#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
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

ListNode* reverseList(ListNode* head)
{
    ListNode *list = NULL;
    ListNode *node;
    while(head)
    {
        node = head->next;
        head->next = list;
        list = head;
        head = node;
    }
    return list;
}

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverseList(slow);
    while(slow)
    {
        if(head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

bool isPalindrome2(ListNode *head)
{
    if(head == NULL) return true;
    bool isPalindrome = true;
    ListNode *slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverseList(slow);
    ListNode *node = slow;
    while(true)
    {
        if(head->val != node->val)
        {
            isPalindrome = false;
            break;
        }
        node = node->next;
        if(node == NULL) break;
        head = head->next;
    }
    slow = reverseList(slow);
    if(head == slow) head->next = slow->next;
    else head->next = slow;
    return isPalindrome;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node = head;
    for(int i = 2;i <= 3;++i)
    {
        node->next = new ListNode(i);
        node = node->next;
    }
    for(int i = 3;i >= 1;--i)
    {
        node->next = new ListNode(i);
        node = node->next;
    }
    PrintListNode(head);
    cout << isPalindrome2(head) << endl;
    PrintListNode(head);
    return 0;
}

