#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

TreeNode* sortedListToBST(ListNode *begin, int len)
{
    if (len == 0) return NULL;
    ListNode *node = begin;
    for (int i = 2; i <= len; i += 2)
        node = node->next;
    TreeNode *root = new TreeNode(node->val);
    root->left = sortedListToBST(begin, len >> 1);
    root->right = sortedListToBST(node->next, len - (len >> 1) - 1);
    return root;
}

TreeNode* sortedListToBST(ListNode *head)
{
    int len = 0;
    for (ListNode *node = head; node != NULL; ++len)
        node = node->next;
    return sortedListToBST(head, len);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

