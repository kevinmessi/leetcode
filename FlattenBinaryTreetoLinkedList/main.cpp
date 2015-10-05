#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root)
{
    if(root && (root->left || root->right))
    {
        flatten(root->right);
        if(root->left)
        {
            flatten(root->left);
            TreeNode* node = root->left;
            while (node->right)
            {
                node = node->right;
            }
            node->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
}

int main()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    //    node->right = new TreeNode(3);
    flatten(node);
    cout << "Hello World!" << endl;
    return 0;
}

