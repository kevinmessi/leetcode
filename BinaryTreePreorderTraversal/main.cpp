#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    if(root == NULL) return vector<int>();
    vector<int> v, tmp;
    v.push_back(root->val);
    tmp = preorderTraversal(root->left);
    v.insert(v.end(),tmp.begin(),tmp.end());
    tmp = preorderTraversal(root->right);
    v.insert(v.end(),tmp.begin(),tmp.end());
    return v;
}

int main()
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    t1->left = t2;
    cout << preorderTraversal(t1).size() <<endl;

    delete t2;
    t2 = NULL;
    delete t1;
    t1 = NULL;
    return 0;
}

