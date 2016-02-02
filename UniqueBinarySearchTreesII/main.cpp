#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

vector<TreeNode*> generateTrees1(int begin, int end)
{
    if (begin > end) return{ NULL };
    vector<TreeNode*> result;
    for (int i = begin; i <= end; ++i)
    {
        vector<TreeNode*> left_trees = generateTrees1(begin, i - 1);
        vector<TreeNode*> right_trees = generateTrees1(i + 1, end);
        for (auto left : left_trees)
        {
            for (auto right : right_trees)
            {
                TreeNode *node = new TreeNode(i);
                node->left = left;
                node->right = right;
                result.push_back(node);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees1(int n)
{
    if (n == 0) return{};
    return generateTrees1(1, n);
}

vector<TreeNode*> generateTrees2(int n)
{
    if (n == 0) return{};
    vector<vector<vector<TreeNode*>>> trees(n + 1);
    trees[0] = vector<vector<TreeNode*>>(n + 2, { NULL });
    for (int i = 1; i <= n; ++i)
    {
        trees[i] = vector<vector<TreeNode*>>(n - i + 2, vector<TreeNode*>());
        for (int j = 1; j <= n - i + 1; ++j)
        {
            for (int k = j; k < i + j; ++k)
            {
                for (auto left : trees[k - j][j])
                {
                    for (auto right : trees[i + j - k - 1][k + 1])
                    {
                        TreeNode *node = new TreeNode(k);
                        node->left = left;
                        node->right = right;
                        trees[i][j].push_back(node);
                    }
                }
            }
        }
    }
    return trees[n][1];
}

TreeNode *add_tree(TreeNode *tree, int n)
{
    if (!tree) return NULL;
    TreeNode *added_tree = new TreeNode(tree->val + n);
    added_tree->left = add_tree(tree->left, n);
    added_tree->right = add_tree(tree->right, n);
    return added_tree;
}

vector<TreeNode*> generateTrees3(int n)
{
    if (n == 0) return{};
    vector<vector<TreeNode*>> trees(n + 1);
    trees[0] = { NULL };
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            for (auto left : trees[j - 1])
            {
                for (auto right : trees[i - j])
                {
                    TreeNode *node = new TreeNode(j);
                    node->left = add_tree(left, 0);
                    node->right = add_tree(right, j);
                    trees[i].push_back(node);
                }
            }
        }
    }
    return trees[n];
}

TreeNode* clone(TreeNode *root)
{
    if (!root) return NULL;
    TreeNode *newroot = new TreeNode(root->val);
    newroot->left = clone(root->left);
    newroot->right = clone(root->right);
    return newroot;
}

vector<TreeNode*> generateTrees(int n)
{
    if (n == 0) return{};
    vector<TreeNode*> trees{ NULL };
    for (int i = 1; i <= n; ++i)
    {
        vector<TreeNode*> temp(move(trees));
        for (auto root : temp)
        {
            TreeNode *current = new TreeNode(i);
            current->left = clone(root);
            trees.push_back(current);
            if (root)
            {
                TreeNode *node = root;
                while (node->right)
                {
                    TreeNode *right_node = node->right;
                    TreeNode *current = new TreeNode(i);
                    node->right = current;
                    current->left = right_node;
                    trees.push_back(clone(root));
                    node->right = right_node;
                    node = node->right;
                }
                node->right = new TreeNode(i);
                trees.push_back(clone(root));
                node->right = NULL;
            }
        }
    }
    return trees;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

