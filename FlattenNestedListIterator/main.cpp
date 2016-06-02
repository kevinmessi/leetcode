#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator1
{
public:
    NestedIterator1(vector<NestedInteger> &nestedList)
    {
        stack_.emplace(&nestedList, 0);
        Travel();
    }

    int next()
    {
        int next_val = val_;
        Travel();
        return next_val;
    }

    bool hasNext()
    {
        return !stack_.empty();
    }

private:
    stack<pair<const vector<NestedInteger> *, size_t>> stack_;
    int val_;

    void Travel()
    {
        while (!stack_.empty())
        {
            auto pair_list_index = stack_.top();
            const vector<NestedInteger> *list = pair_list_index.first;
            size_t idx = pair_list_index.second;
            stack_.pop();
            while (idx < list->size())
            {
                stack_.emplace(list, idx + 1);
                if (list->at(idx).isInteger())
                {
                    val_ = list->at(idx).getInteger();
                    return;
                }
                list = &(list->at(idx).getList());
                idx = 0;
            }
        }
    }
};

class NestedIterator2
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        begins_.push(nestedList.begin());
        ends_.push(nestedList.end());
    }

    int next()
    {
        hasNext();
        int val = begins_.top()->getInteger();
        ++begins_.top();
        return val;
    }

    bool hasNext()
    {
        while (!begins_.empty())
        {
            if (begins_.top() == ends_.top())
            {
                begins_.pop();
                ends_.pop();
            }
            else
            {
                auto x = begins_.top();
                if (x->isInteger()) return true;
                ++begins_.top();
                auto &list = x->getList();
                begins_.push(list.begin());
                ends_.push(list.end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::const_iterator> begins_, ends_;
};

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); ++iter)
            list_.push(&(*iter));
    }

    int next()
    {
        hasNext();
        int val = list_.top()->getInteger();
        list_.pop();
        return val;
    }

    bool hasNext()
    {
        while (!list_.empty())
        {
            const NestedInteger *num = list_.top();
            if (num->isInteger()) return true;
            list_.pop();
            const vector<NestedInteger> &sub_list = num->getList();
            for (auto iter = sub_list.rbegin(); iter != sub_list.rend(); ++iter)
                list_.push(&(*iter));
        }
        return false;
    }

private:
    stack<const NestedInteger*> list_;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
