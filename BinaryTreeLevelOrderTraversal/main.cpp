#include <iostream>
#include <vector>

using namespace std;

void PrintArray(vector<int> v)
{
    int len = v.size();
    for(int i = 0;i < len;++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root)
{
    vector<vector<int> > levels;
    if(NULL == root) return levels;
    vector<int> level;
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    while(!nodes.empty())
    {
        vector<TreeNode*> tmp = nodes;
        nodes.clear();
        level.clear();
        int len = tmp.size();
        for(int i = 0;i < len;++i)
        {
            level.push_back(tmp[i]->val);
            if(tmp[i]->left) nodes.push_back(tmp[i]->left);
            if(tmp[i]->right) nodes.push_back(tmp[i]->right);
        }
        levels.push_back(level);
    }
    return levels;
}

int main()
{
    levelOrder(NULL);
    vector<int> v = {1,2,3};
    vector<int> v2 = v;
    v2.push_back(4);
    PrintArray(v);
    PrintArray(v2);
    return 0;
}

