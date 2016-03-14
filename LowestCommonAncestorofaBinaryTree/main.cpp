#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

int lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode* &lca)
{
    int n = 0;
    if (!root) return n;
    if (root == p || root == q) ++n;
    n += lowestCommonAncestor(root->left, p, q, lca) + lowestCommonAncestor(root->right, p, q, lca);
    if (lca == NULL && n == 2) lca = root;
    return n;
}

TreeNode* lowestCommonAncestor1(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *lca = NULL;
    lowestCommonAncestor(root, p, q, lca);
    return lca;
}

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

