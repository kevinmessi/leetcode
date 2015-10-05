#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack2
{
public:
    void push(int x)
    {
        s_.push(x);
        if(min_.empty() || x <= min_.top()) min_.push(x);
    }

    void pop()
    {
        if(s_.top() == min_.top()) min_.pop();
        s_.pop();
    }

    int top()
    {
        return s_.top();
    }

    int getMin()
    {
        return min_.top();
    }

private:
    stack<int> s_;
    stack<int> min_;
};

class MinStack
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    MinStack()
    {
        s_ = NULL;
        min_ = NULL;
    }

    ~MinStack()
    {
        ListNode *list = s_;
        ListNode *tmp;
        while(list)
        {
            tmp = list;
            list = list->next;
            delete tmp;
        }
        list = min_;
        while(list)
        {
            tmp = list;
            list = list->next;
            delete tmp;
        }
    }

    void push(int x)
    {
        ListNode *node = new ListNode(x);
        node->next = s_;
        s_ = node;
        if(!min_ || x <= min_->val)
        {
            ListNode *min_node = new ListNode(x);
            min_node->next = min_;
            min_ = min_node;
        }
    }

    void pop()
    {
        ListNode *tmp;
        if(s_->val == min_->val)
        {
            tmp = min_;
            min_ = min_->next;
            delete tmp;
        }
        tmp = s_;
        s_ = s_->next;
        delete tmp;
    }

    int top()
    {
        return s_->val;
    }

    int getMin()
    {
        return min_->val;
    }

private:
    ListNode *s_;
    ListNode *min_;
};

int main()
{
    vector<int> v{1,2,3,4,5};
    cout << "Hello World!" << endl;
    return 0;
}

