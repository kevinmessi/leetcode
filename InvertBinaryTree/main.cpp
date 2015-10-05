#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root)
{
    if(root)
    {
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}

TreeNode* invertTree2(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *node = q.front();
        if(node)
        {
            swap(node->left, node->right);
            q.push(node->left);
            q.push(node->right);
        }
        q.pop();
    }
    return root;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

