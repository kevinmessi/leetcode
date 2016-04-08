#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

void connect(TreeLinkNode *root)
{
    while (root)
    {
        TreeLinkNode *node = root, *pre = NULL;
        while (node)
        {
            if (node->left)
            {
                if (pre) pre->next = node->left;
                else root = node->left;
                pre = node->left;
            }
            if (node->right)
            {
                if (pre) pre->next = node->right;
                else root = node->right;
                pre = node->right;
            }
            node = node->next;
        }
        if (!pre) break;
    }
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
