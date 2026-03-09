#include <iostream>
#include <queue>
using namespace std;

class Stack
{
private:
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);

        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed\n";
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
        cout << "Top element popped\n";
    }

    int peek()
    {
        if (q.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    int getSize()
    {
        return q.size();
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Size: " << s.getSize() << "\n";
    cout << "Top: " << s.peek() << "\n";
    s.pop();
    return 0;
}