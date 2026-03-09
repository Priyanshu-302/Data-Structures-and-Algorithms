#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1, s2;

public:
    void push(int x)
    {
        s1.push(x);
        cout << x << " pushed\n";
    }

    void pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
        cout << "Front element popped\n";
    }

    int peek()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    int getSize()
    {
        return s1.size() + s2.size();
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Size: " << q.getSize() << "\n";
    cout << "Front: " << q.peek() << "\n";
    q.pop();
    return 0;
}