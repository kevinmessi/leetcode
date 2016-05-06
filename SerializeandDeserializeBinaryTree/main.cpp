#include <iostream>
#include <queue>
#include <sstream>

#include "../toolkit/data_structure.h"

using namespace std;

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        stringstream ss;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node)
            {
                ss << node->val << ",";
                q.push(node->left);
                q.push(node->right);
            }
            else ss << "#,";
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        TreeNode dummy(0);
        queue<TreeNode *> q;
        q.push(&dummy);
        stringstream ss(data);
        string str;
        bool is_right = true;
        while (getline(ss, str, ','))
        {
            if (str.empty()) continue;
            TreeNode *parent = q.front();
            if (is_right) q.pop();
            TreeNode *node = NULL;
            if (str != "#")
            {
                node = new TreeNode(stoi(str));
                q.push(node);
            }
            if (is_right) parent->right = node;
            else parent->left = node;
            is_right = !is_right;
        }
        return dummy.right;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
