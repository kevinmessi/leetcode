#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> traversal;
    if(root)
    {
        traversal = inorderTraversal(root->left);
        traversal.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        traversal.insert(traversal.end(),right.begin(),right.end());
    }
    return traversal;
}

bool isSymmetric(TreeNode* tree1, TreeNode* tree2)
{
    if(!tree1)
    {
        if(!tree2) return true;
        else return false;
    }
    if(!tree2) return false;
    if(tree1->val != tree2->val) return false;
    return isSymmetric(tree1->left, tree2->right) && isSymmetric(tree1->right, tree2->left);
}

bool isSymmetric(TreeNode* root)
{
    if(!root) return true;
    else return isSymmetric(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << isSymmetric(root) << endl;
    delete root;
    return 0;
}

