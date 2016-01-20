#include <iostream>
#include <vector>

#include "../toolkit/data_structure.h"

using namespace std;

void pathSum(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &paths)
{
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right && sum == root->val)
        paths.push_back(path);
    pathSum(root->left, sum - root->val, path, paths);
    pathSum(root->right, sum - root->val, path, paths);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> paths;
    vector<int> path;
    pathSum(root, sum, path, paths);
    return paths;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

