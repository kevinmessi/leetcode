/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined
 * as a binary tree in which the depth of the two subtrees
 * of every node never differ by more than 1.
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Info
{
    int balanced;
    int depth;
    Info(int b,int h) : balanced(b), depth(h) {}
};

Info balanced(TreeNode* root)
{
    Info info(true, 0);
    if(root == NULL) return info;
    Info left_info = balanced(root->left);
    Info right_info = balanced(root->right);
    info.balanced = left_info.balanced && right_info.balanced
            && abs(left_info.depth - right_info.depth) <= 1;
    info.depth = 1 + max(left_info.depth, right_info.depth);
    return info;
}

bool isBalanced(TreeNode* root)
{
    return balanced(root).balanced;
}

int balancedHeight(TreeNode* root)
{
    if(root == NULL) return 0;
    int lh = balancedHeight(root->left);
    int rh = balancedHeight(root->right);
    if(lh < 0 || rh < 0 || abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool isBalanced2(TreeNode* root)
{
    return balancedHeight(root) >= 0;
}

int main()
{
    TreeNode tree(1);
    cout << isBalanced2(&tree) << endl;
    return 0;
}

