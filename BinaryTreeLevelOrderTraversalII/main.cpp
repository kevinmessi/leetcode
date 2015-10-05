#include <iostream>
#include <vector>
#include <stack>

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

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
    vector<vector<int> > bottom;
    if(NULL == root) return bottom;
    stack<vector<int> > levels;
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
        levels.push(level);
    }
    while(!levels.empty())
    {
        bottom.push_back(levels.top());
        levels.pop();
    }
    return bottom;
}

int main()
{
    levelOrderBottom(NULL);
    cout << "Hello World!" << endl;
    return 0;
}

