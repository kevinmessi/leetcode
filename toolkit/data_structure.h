#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stddef.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif
