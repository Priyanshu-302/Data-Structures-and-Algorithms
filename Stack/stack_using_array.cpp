#include <iostream>
using namespace std;

class Stack
{
private:
    int st[10];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    int push(int x)
    {
        if (top >= 9)
        {
            cout << "Stack Overflow" << endl;
            return -1;
        }
        else
        {
            top++;
            st[top] = x;
            return x;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        
        return st[top];
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack elements are: ";
            for (int i = 0; i <= top; i++)
            {
                cout << st[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top: " << s.peek() << "\n";

    s.pop();
    s.display();

    return 0;
}