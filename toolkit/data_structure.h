#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stddef.h>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct UndirectedGraphNode
{
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

#endif
