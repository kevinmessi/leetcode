#include <iostream>
#include <stack>

#include "../toolkit/data_structure.h"

using namespace std;

int kthSmallest1(TreeNode* root, int k)
{
    stack<TreeNode*> nodes;
    while (root || !nodes.empty())
    {
        while (root)
        {
            nodes.push(root);
            root = root->left;
        }
        if (!nodes.empty())
        {
            root = nodes.top();
            if (--k == 0) return root->val;
            nodes.pop();
            root = root->right;
        }
    }
    return -1;
}

void kthSmallest2(TreeNode *root, int &count, int &num)
{
    if (count <= 0) return;
    if (root->left) kthSmallest2(root->left, count, num);
    if (--count == 0)
    {
        num = root->val;
        return;
    }
    if (root->right) kthSmallest2(root->right, count, num);
}

int kthSmallest2(TreeNode *root, int k)
{
    int num = -1, count = k;
    if (root) kthSmallest2(root, count, num);
    return num;
}

int count(TreeNode *root, int k, int &num)
{
    if (!root || k == 0) return 0;
    int left_count = count(root->left, k, num) + 1;
    if (left_count == k) num = root->val;
    return left_count + count(root->right, k - left_count, num);
}

int kthSmallest(TreeNode *root, int k)
{
    int num = -1;
    if (root) count(root, k, num);
    return num;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

