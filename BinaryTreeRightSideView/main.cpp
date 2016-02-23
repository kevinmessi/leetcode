#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

vector<int> rightSideView1(TreeNode* root)
{
    vector<int> rights;
    if (!root) return rights;
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    while (!nodes.empty())
    {
        rights.push_back(nodes.back()->val);
        vector<TreeNode*> temp(move(nodes));
        for (TreeNode *node : temp)
        {
            if (node->left) nodes.push_back(node->left);
            if (node->right) nodes.push_back(node->right);
        }
    }
    return rights;
}

void rightSideView(TreeNode *node, size_t depth, vector<int> &rights)
{
    if (!node) return;
    if (depth == rights.size()) rights.push_back(node->val);
    rightSideView(node->right, depth + 1, rights);
    rightSideView(node->left, depth + 1, rights);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> rights;
    rightSideView(root, 0, rights);
    return rights;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

