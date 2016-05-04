#include <iostream>
#include <unordered_map>

#include "../toolkit/data_structure.h"

using namespace std;

RandomListNode *copyRandomList1(RandomListNode *head)
{
    unordered_map<RandomListNode*, RandomListNode*> table;
    RandomListNode dummy(0), *node = &dummy;
    while (head)
    {
        if (table.find(head) == table.end())
        {
            node->next = new RandomListNode(head->label);
            table[head] = node->next;
        }
        else
        {
            node->next = table[head];
        }
        node = node->next;
        if (head->random)
        {
            if (table.find(head->random) == table.end())
            {
                node->random = new RandomListNode(head->random->label);
                table[head->random] = node->random;
            }
            else
            {
                node->random = table[head->random];
            }
        }
        head = head->next;
    }
    return dummy.next;
}

RandomListNode *copyRandomList2(RandomListNode *head)
{
    unordered_map<RandomListNode*, RandomListNode*> table;
    RandomListNode dummy(0), *copy = &dummy, *node = head;
    while (node)
    {
        copy->next = new RandomListNode(node->label);
        copy = copy->next;
        table[node] = copy;
        node = node->next;
    }
    node = head;
    copy = dummy.next;
    while (node)
    {
        if (node->random) copy->random = table[node->random];
        copy = copy->next;
        node = node->next;
    }
    return dummy.next;
}

RandomListNode *copyRandomList3(RandomListNode *head)
{
    RandomListNode *copy = NULL, *l1, *l2;
    for (l1 = head; l1 != NULL; l1 = l2->next)
    {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }
    for (l1 = head; l1 != NULL; l1 = l2->next)
    {
        l2 = l1->next;
        if (l1->random) l2->random = l1->random->next;
    }
    if (head) copy = head->next;
    for (l1 = head; l1 != NULL; l1 = l1->next)
    {
        l2 = l1->next;
        l1->next = l2->next;
        if (l1->next) l2->next = l1->next->next;
    }
    return copy;
}

RandomListNode *copyRandomList4(RandomListNode *head)
{
    RandomListNode *copy = NULL, *l1, *l2;
    for (l1 = head; l1 != NULL; l1 = l1->next)
    {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->random;
        l1->random = l2;
    }
    for (l1 = head; l1 != NULL; l1 = l1->next)
    {
        l2 = l1->random;
        if (l2->next) l2->random = l2->next->random;
    }
    if (head) copy = head->random;
    for (l1 = head; l1 != NULL; l1 = l1->next)
    {
        l2 = l1->random;
        l1->random = l2->next;
        l2->next = l1->next ? l1->next->random : NULL;
    }
    return copy;
}

RandomListNode *copyRandomList(RandomListNode *head)
{
    RandomListNode dummy(0), *node = head;
    while (node)
    {
        RandomListNode *temp = node->next;
        RandomListNode *copy = new RandomListNode(node->label);
        copy->next = temp;
        node->next = copy;
        node = temp;
    }
    node = head;
    while (node)
    {
        if (node->random) node->next->random = node->random->next;
        node = node->next->next;
    }
    if (head) dummy.next = head->next;
    node = head;
    while (node)
    {
        RandomListNode *temp = node->next;
        node->next = temp->next;
        node = node->next;
        if (node) temp->next = node->next;
    }
    return dummy.next;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
