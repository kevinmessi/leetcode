#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

int countNodes1(TreeNode *root)
{
    if (!root) return 0;
    int l = 0, r = 0;
    for (TreeNode *node = root->left; node; node = node->left)
        ++l;
    for (TreeNode *node = root->right; node; node = node->left)
        ++r;
    return (1 << r) + (l > r ? countNodes1(root->left) : countNodes1(root->right));
}

int countNodes2(TreeNode *root)
{
    int hl = 0, hr = 0;
    for (TreeNode *node = root; node; node = node->left)
        ++hl;
    for (TreeNode *node = root; node; node = node->right)
        ++hr;
    if (hl == hr) return (1 << hl) - 1;
    return 1 + countNodes2(root->left) + countNodes2(root->right);
}

int countNodes3(TreeNode *root)
{
    int count = 0, l = 0;
    for (TreeNode *node = root; node; node = node->left)
        ++l;
    while (root)
    {
        --l;
        int r = 0;
        for (TreeNode *node = root->right; node; node = node->left)
            ++r;
        count += (1 << r);
        root = r == l ? root->right : root->left;
    }
    return count;
}

int countNodes4(TreeNode *root)
{
    if (!root) return 0;
    int count = 1, l = 0;
    for (TreeNode *node = root; node; node = node->left)
        ++l;
    while (--l)
    {
        int r = 0;
        for (TreeNode *node = root->right; node; node = node->left)
            ++r;
        count <<= 1;
        if (r == l)
        {
            count |= 1;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return count;
}

int countNodes(TreeNode *root)
{
    if (!root) return 0;
    int l = 0;
    for (TreeNode *node = root; node; node = node->left)
        ++l;
    int count = (1 << (l - 1)) - 1;
    while (--l)
    {
        TreeNode *node = root->left;
        for (int i = 1; i < l; ++i)
            node = node->right;
        if (node)
        {
            count += 1 << (l - 1);
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    if (root) ++count;
    return count;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

