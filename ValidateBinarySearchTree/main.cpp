#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

bool isValidBST1(TreeNode* root, int &min, int &max)
{
    if (!root) return true;
    int lMin = root->val, lMax = root->val, rMin = root->val, rMax = root->val;
    bool lValid = !root->left || (isValidBST1(root->left, lMin, lMax) && lMax < root->val);
    if (!lValid) return false;
    bool rValid = !root->right || (isValidBST1(root->right, rMin, rMax) && rMin > root->val);
    min = lMin, max = rMax;
    return rValid;
}

bool isValidBST1(TreeNode* root)
{
    int min, max;
    return isValidBST1(root, min, max);
}

// https://leetcode.com/discuss/45425/c-simple-recursive-solution
bool isValidBST2(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
    if (!root) return true;
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
        return false;
    return isValidBST2(root->left, minNode, root) && isValidBST2(root->right, root, maxNode);
}

bool isValidBST2(TreeNode* root)
{
    return isValidBST2(root, NULL, NULL);
}

// https://leetcode.com/discuss/14886/order-traversal-please-rely-buggy-int_max-int_min-solutions
bool isValidBST(TreeNode* node, TreeNode* &prev)
{
    if (!node) return true;
    if (!isValidBST(node->left, prev)) return false;
    if (prev && prev->val >= node->val) return false;
    prev = node;
    return isValidBST(node->right, prev);
}

bool isValidBST(TreeNode* root)
{
    TreeNode* prev = NULL;
    return isValidBST(root, prev);
}

int main()
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(1);
    cout << isValidBST(node) << endl;
    return 0;
}

