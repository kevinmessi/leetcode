#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
    // Push element x to the back of queue.
    void push(int x)
    {
        push_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        peek();
        pop_stack.pop();
    }

    // Get the front element.
    int peek(void)
    {
        if(pop_stack.empty())
        {
            while(!push_stack.empty())
            {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        return pop_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return push_stack.empty() && pop_stack.empty();
    }

private:
    stack<int> push_stack, pop_stack;
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    q.pop();
    cout << q.empty() << endl;
    return 0;
}

