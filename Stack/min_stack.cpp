#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> s, min_stack;

public:
    MinStack() {}

    void push(int val)
    {
        s.push(val);
        if (min_stack.empty() || val <= min_stack.top())
            min_stack.push(val);
        return;
    }

    void pop()
    {
        if (s.top() == min_stack.top())
            min_stack.pop();
        s.pop();
        return;
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.top() << endl; // return 0
    cout << minStack.getMin() << endl; // return -2
    return 0;
}