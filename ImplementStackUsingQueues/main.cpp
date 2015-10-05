#include <iostream>
#include <queue>

using namespace std;

class Stack
{
public:
    // Push element x onto stack.
    void push(int x)
    {
        q.push(x);
        int len = q.size();
        for(int i = 0;i < len - 1;++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop()
    {
        q.pop();
    }

    // Get the top element.
    int top()
    {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.empty() << endl;
    return 0;
}

