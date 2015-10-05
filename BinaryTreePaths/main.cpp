#include "../toolkit/print.h"
#include "../toolkit/data_structure.h"

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//vector<string> binaryTreePaths(TreeNode* root)
//{
//    vector<string> paths;
//    if(root)
//    {
//        if(root->left || root->right)
//        {
//            if(root->left)
//            {
//                vector<string> sub_paths = binaryTreePaths(root->left);
//                for(string s : sub_paths)
//                {
//                    paths.push_back(to_string(root->val) + "->" + s);
//                }
//            }
//            if(root->right)
//            {
//                vector<string> sub_paths = binaryTreePaths(root->right);
//                for(string s : sub_paths)
//                {
//                    paths.push_back(to_string(root->val) + "->" + s);
//                }
//            }
//        }
//        else
//        {
//            paths.push_back(to_string((root->val)));
//        }
//    }
//    return paths;
//}

void binaryTreePaths(vector<string>& result, TreeNode* root, string t)
{
    if(!root->left && !root->right)
    {
        result.push_back(t);
        return;
    }
    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> result;
    if(!root) return result;
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}

int main()
{
    PrintVector(binaryTreePaths(NULL));
    return 0;
}

