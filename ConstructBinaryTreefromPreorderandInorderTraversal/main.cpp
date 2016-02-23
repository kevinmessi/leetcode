#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder,
                     int pbegin, int pend, int ibegin, int iend,
                     unordered_map<int, int> &m)
{
    if (pbegin > pend) return NULL;
    TreeNode *root = new TreeNode(preorder[pbegin]);
    int i = m[preorder[pbegin]];
    root->left = buildTree1(preorder, inorder, pbegin + 1, pbegin + i - ibegin, ibegin, i - 1, m);
    root->right = buildTree1(preorder, inorder, pbegin + i - ibegin + 1, pend, i + 1, iend, m);
    return root;
}

TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder)
{
    unordered_map<int, int> m;
    int len = inorder.size();
    for (int i = 0; i < len; ++i)
        m[inorder[i]] = i;
    return buildTree1(preorder, inorder, 0, len - 1, 0, len - 1, m);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    int len = preorder.size();
    if (len == 0) return NULL;
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode*> s;
    s.push(root);
    int i = 0, j = 0;
    while (i + 1 < len)
    {
        TreeNode *node = s.top();
        if (node->val != inorder[j])
        {
            node->left = new TreeNode(preorder[++i]);
            s.push(node->left);
        }
        else
        {
            s.pop();
            ++j;
            if (s.empty() || s.top()->val != inorder[j])
            {
                node->right = new TreeNode(preorder[++i]);
                s.push(node->right);
            }
        }
    }
    return root;
}

int main()
{
    vector<int> preorder;
    vector<int> inorder;
    cout << buildTree(preorder, inorder) << endl;
    return 0;
}

