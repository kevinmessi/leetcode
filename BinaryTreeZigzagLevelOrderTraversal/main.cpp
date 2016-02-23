#include <iostream>
#include <queue>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

vector<vector<int>> zigzagLevelOrder1(TreeNode* root)
{
    vector<vector<int>> result;
    if (!root) return result;
    bool inverse = false;
    vector<TreeNode*> nodes(1, root);
    while (!nodes.empty())
    {
        vector<TreeNode*> temp(move(nodes));
        int len = temp.size();
        vector<int> layer(len);
        for (int i = 0; i < len; ++i)
        {
            int idx = inverse ? len - i - 1 : i;
            layer[i] = temp[idx]->val;
            if (temp[i]->left) nodes.push_back(temp[i]->left);
            if (temp[i]->right) nodes.push_back(temp[i]->right);
        }
        inverse = !inverse;
        result.push_back(layer);
    }
    return result;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    if (!root) return result;
    bool inverse = false;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        int len = nodes.size();
        vector<int> layer(len);
        for (int i = 0; i < len; ++i)
        {
            TreeNode *node = nodes.front();
            nodes.pop();
            int idx = inverse ? len - i - 1 : i;
            layer[idx] = node->val;
            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
        }
        inverse = !inverse;
        result.push_back(layer);
    }
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

