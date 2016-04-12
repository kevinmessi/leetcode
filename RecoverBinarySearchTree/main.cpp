#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

void inorder_traversal1(TreeNode *root, vector<TreeNode*> &nodes)
{
    if (!root) return;
    inorder_traversal1(root->left, nodes);
    nodes.push_back(root);
    inorder_traversal1(root->right, nodes);
}

void recoverTree1(TreeNode *root)
{
    vector<TreeNode*> nodes;
    inorder_traversal1(root, nodes);
    TreeNode *first = NULL, *second = NULL;
    int len = nodes.size();
    for (int i = 0; i < len - 1; ++i)
    {
        if (!first && nodes[i]->val > nodes[i + 1]->val)
            first = nodes[i];
        if (first && nodes[i]->val > nodes[i + 1]->val)
            second = nodes[i + 1];
    }
    swap(first->val, second->val);
}

void inorder_traversal2(TreeNode *root, TreeNode *&pre, TreeNode *&first, TreeNode *&second)
{
    if (!root) return;
    inorder_traversal2(root->left, pre, first, second);
    if (!first && pre->val > root->val)
        first = pre;
    if (first && pre->val > root->val)
        second = root;
    pre = root;
    inorder_traversal2(root->right, pre, first, second);
}

void recoverTree2(TreeNode *root)
{
    TreeNode *pre = new TreeNode(INT_MIN), *first = NULL, *second = NULL;
    inorder_traversal2(root, pre, first, second);
    swap(first->val, second->val);
}

void recoverTree(TreeNode *root)
{
    TreeNode *pre = new TreeNode(INT_MIN), *first = NULL, *second = NULL;
    while (root)
    {
        TreeNode *node = root->left;
        if (!node)
        {
            if (!first && pre->val > root->val) first = pre;
            if (first && pre->val > root->val) second = root;
            pre = root;
            root = root->right;
        }
        else
        {
            while (node->right && node->right != root)
                node = node->right;
            if (!node->right)
            {
                node->right = root;
                root = root->left;
            }
            else
            {
                if (!first && pre->val > root->val) first = pre;
                if (first && pre->val > root->val) second = root;
                pre = root;
                node->right = NULL;
                root = root->right;
            }
        }
    }
    swap(first->val, second->val);
}

int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    recoverTree(root);
    cout << "Hello World!" << endl;
    return 0;
}
