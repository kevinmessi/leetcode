#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

int sumNumbers(TreeNode* root, int s)
{
    if (!root) return 0;
    s = root->val + 10 * s;
    if (!root->left && !root->right)
        return s;
    return sumNumbers(root->left, s) + sumNumbers(root->right, s);
}

int sumNumbers(TreeNode* root)
{
    return sumNumbers(root, 0);
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

