#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum)
{
    if(root == NULL) return false;
    int v = root->val;
    TreeNode *l = root->left, *r = root->right;
    if(l == NULL)
    {
        if(r == NULL) return v == sum;
        else return hasPathSum(r, sum - v);
    }
    if(r == NULL) return hasPathSum(l, sum - v);
    return hasPathSum(l, sum - v) || hasPathSum(r, sum - v);
}

int main()
{
    cout << INT_MAX << endl;
    return 0;
}

