#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder,
                     int ibegin, int iend, int pbegin, int pend,
                     unordered_map<int, int> &m)
{
    if (pbegin > pend) return NULL;
    TreeNode *root = new TreeNode(postorder[pend]);
    int i = m[postorder[pend]];
    root->left = buildTree1(inorder, postorder, ibegin, i - 1, pbegin, pbegin + i - ibegin - 1, m);
    root->right = buildTree1(inorder, postorder, i + 1, iend, pbegin + i - ibegin, pend - 1, m);
    return root;
}

TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder)
{
    unordered_map<int, int> m;
    int len = inorder.size();
    for (int i = 0; i < len; ++i)
        m[inorder[i]] = i;
    return buildTree1(inorder, postorder, 0, len - 1, 0, len - 1, m);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int len = postorder.size();
    if (len == 0) return NULL;
    TreeNode *root = new TreeNode(postorder[len - 1]);
    stack<TreeNode*> s;
    s.push(root);
    int i = len - 1, j = len - 1;
    while (i > 0)
    {
        TreeNode *node = s.top();
        if (node->val != inorder[j])
        {
            node->right = new TreeNode(postorder[--i]);
            s.push(node->right);
        }
        else
        {
            s.pop();
            --j;
            if (s.empty() || s.top()->val != inorder[j])
            {
                node->left = new TreeNode(postorder[--i]);
                s.push(node->left);
            }
        }
    }
    return root;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

