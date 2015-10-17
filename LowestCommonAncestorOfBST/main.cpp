#include "../toolkit/data_structure.h"
#include <iostream>

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || !p || !q) return NULL;
    if(root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!p || !q) return NULL;
    while (root)
    {
        if (root->val > p->val && root->val > q->val)
            root = root->left;
        else if (root->val < p->val && root->val < q->val)
            root = root->right;
        else
            break;
    }
    return root;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

