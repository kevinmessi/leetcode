#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end)
{
    if (begin > end) return NULL;
    int mid = begin + (end - begin) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, begin, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

