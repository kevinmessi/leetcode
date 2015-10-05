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

TreeNode* lowestCommonAncesto2r(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || !p || !q) return NULL;
    TreeNode* ans = root;
    TreeNode* r = root;
    TreeNode* k = root;
    while(r != p || k != q)
    {
        if(p->val < r->val)
            r = r->left;
        else if(p->val > r->val)
            r = r->right;
        if(q->val < k->val)
            k = k->left;
        else if( q->val > k->val)
            k = k->right;
        if(r == k)
            ans = r;
        else
            break;
    }
    return ans;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

