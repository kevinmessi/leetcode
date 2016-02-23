#include <iostream>
#include <stack>

#include "../toolkit/data_structure.h"

using namespace std;

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            nodes.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *node = nodes.top();
        int smallest = node->val;
        nodes.pop();
        node = node->right;
        while (node)
        {
            nodes.push(node);
            node = node->left;
        }
        return smallest;
    }
private:
    stack<TreeNode*> nodes;
};

int main()
{
    TreeNode *root = new TreeNode(1);
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
    return 0;
}

