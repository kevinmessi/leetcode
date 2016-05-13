#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack1
{
public:
    MinStack1()
    {
    }

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

class MinStack2
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    MinStack2()
    {
        s_ = NULL;
        min_ = NULL;
    }

    ~MinStack2()
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

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int x)
    {
        if (s_.empty())
        {
            min_ = x;
            s_.push(0);
        }
        else
        {
            s_.push(x - min_);
            if (x < min_) min_ = x;
        }
    }

    void pop()
    {
        long long gap = s_.top();
        s_.pop();
        if (gap < 0) min_ -= gap;
    }

    int top()
    {
        long long gap = s_.top();
        return int(min_ + (gap < 0 ? 0 : gap));
    }

    int getMin()
    {
        return int(min_);
    }

private:
    stack<long long> s_;
    long long min_;
};

int main()
{
    vector<int> v{1,2,3,4,5};
    cout << "Hello World!" << endl;
    return 0;
}

