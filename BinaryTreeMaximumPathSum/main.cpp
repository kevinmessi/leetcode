#include <iostream>

#include "../toolkit/data_structure.h"

using namespace std;

int maxPathSum1(TreeNode *root, int &sum)
{
    int max_sum = INT_MIN, left_sum = 0, right_sum = 0;
    if (root->left) max_sum = maxPathSum1(root->left, left_sum);
    if (root->right) max_sum = max(max_sum, maxPathSum1(root->right, right_sum));
    sum = max(0, root->val + max(left_sum, right_sum));
    max_sum = max(max_sum, root->val + left_sum + right_sum);
    return max_sum;
}

int maxPathSum1(TreeNode *root)
{
    if (!root) return 0;
    int sum;
    return maxPathSum1(root, sum);
}

int maxPathSum(TreeNode *root, int &sum)
{
    if (!root) return 0;
    int left_sum = maxPathSum(root->left, sum);
    int right_sum = maxPathSum(root->right, sum);
    sum = max(sum, root->val + left_sum + right_sum);
    return max(0, root->val + max(left_sum, right_sum));
}

int maxPathSum(TreeNode *root)
{
    int sum = INT_MIN;
    maxPathSum(root, sum);
    return sum;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
