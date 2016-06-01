#include <iostream>
#include <unordered_map>

#include "../toolkit/data_structure.h"

using namespace std;

int rob(TreeNode *root, unordered_map<TreeNode*, int> &memo)
{
    if (memo.find(root) != memo.end()) return memo[root];
    TreeNode *left_child = root->left, *right_child = root->right;
    return memo[root] = max(
                root->val
                + (left_child ? (rob(left_child->left, memo) + rob(left_child->right, memo)) : 0)
                + (right_child ? (rob(right_child->left, memo) + rob(right_child->right, memo)) : 0)
                ,
                rob(left_child, memo) + rob(right_child, memo)
                );
}

int rob1(TreeNode *root)
{
    unordered_map<TreeNode*, int> memo;
    memo[NULL] = 0;
    return rob(root, memo);
}

void rob(TreeNode *root, int &robbed, int &not_robbed)
{
    if (!root)
    {
        robbed = not_robbed = 0;
        return;
    }
    int left_robbed, left_not_robbed, right_robbed, right_not_robbed;
    rob(root->left, left_robbed, left_not_robbed);
    rob(root->right, right_robbed, right_not_robbed);
    robbed = root->val + left_not_robbed + right_not_robbed;
    not_robbed = max(left_robbed, left_not_robbed) + max(right_robbed, right_not_robbed);
}

int rob(TreeNode *root)
{
    int robbed, not_robbed;
    rob(root, robbed, not_robbed);
    return max(robbed, not_robbed);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
