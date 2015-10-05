#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *one = head;
    ListNode *two = head;
    while(true)
    {
        if(!two || !two->next) return NULL;
        one = one->next;
        two = two->next->next;
        if(one == two) break;
    }
    two = head;
    while(true)
    {
        if(one == two) return two;
        one = one->next;
        two = two->next;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

