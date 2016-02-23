#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

void connect1(TreeLinkNode *root)
{
    if (!root) return;
    TreeLinkNode *node1 = root->left, *node2 = root->right;
    connect1(node1);
    connect1(node2);
    while (node1 && node2)
    {
        node1->next = node2;
        node1 = node1->right;
        node2 = node2->left;
    }
}

void connect2(TreeLinkNode *root)
{
    if (!root) return;
    if (root->left)
    {
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
    }
    connect2(root->left);
    connect2(root->right);
}

void connect(TreeLinkNode *root)
{
    if (!root) return;
    while (root->left)
    {
        TreeLinkNode *node = root;
        while (node)
        {
            node->left->next = node->right;
            if (node->next) node->right->next = node->next->left;
            node = node->next;
        }
        root = root->left;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

