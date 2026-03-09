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

class Queue
{
private:
    Node *front, *rear;
    int size;

public:
    Queue()
    {
        front = rear = nullptr;
        size = 0;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        if (front == nullptr)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        size++;
        cout << x << " enqueued\n";
    }

    void pop()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        cout << front->data << " dequeued\n";
        front = front->next;
        delete temp;
        size--;
    }

    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue (front → rear): ";
        Node *temp = front;
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
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    cout << "Size: " << q.getSize() << "\n";
    cout << "Front: " << q.peek() << "\n";
    q.pop();
    q.display();
    return 0;
}