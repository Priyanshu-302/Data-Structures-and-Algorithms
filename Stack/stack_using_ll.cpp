#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;
    int size;

public:
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
        cout << x << " pushed\n";
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }

        Node *temp = top;
        cout << top->data << " popped\n";
        top = top->next;
        delete temp;
        size--;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return -1;
        }

        return top->data;
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack (top → bottom): ";
        Node *temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Size: " << s.getSize() << "\n";
    cout << "Top: " << s.peek() << "\n";
    s.pop();
    s.display();
    return 0;
}