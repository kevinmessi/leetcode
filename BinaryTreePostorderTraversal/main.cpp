#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> traversal;
    if(root)
    {
        traversal = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        traversal.insert(traversal.end(),right.begin(),right.end());
        traversal.push_back(root->val);
    }
    return traversal;
}

vector<int> postorderTraversal2(TreeNode *root)
{
    vector<int> traversal;
    stack<TreeNode*> s;
    TreeNode *node = NULL, *last, *dummy = new TreeNode(0);
    dummy->right = root;
    s.push(dummy);
    while(!s.empty())
    {
        last = node;
        node = s.top();
        if(last != node->right)
        {
            node = node->right;
            while(node)
            {
                s.push(node);
                node = node->left;
            }
        }
        else
        {
            if(node != dummy) traversal.push_back(node->val);
            s.pop();
        }
    }
    delete dummy;
    return traversal;
}

vector<int> postorderTraversal3(TreeNode *root)
{
    vector<int> traversal;
    if(!root) return traversal;
    stack<TreeNode*> s;
    TreeNode *tmp;
    s.push(root);
    while(!s.empty())
    {
        tmp = s.top();
        s.pop();
        traversal.push_back(tmp->val);
        if(tmp->left) s.push(tmp->left);
        if(tmp->right) s.push(tmp->right);
    }
    reverse(traversal.begin(),traversal.end());
    return traversal;
}

int main()
{
    stack<int> s;
    cout << s.empty() << endl;
    return 0;
}

