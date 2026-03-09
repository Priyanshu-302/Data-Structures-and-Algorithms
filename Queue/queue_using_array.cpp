#include <iostream>
using namespace std;

class Queue
{
private:
    int q[4];
    int front, rear, size;

public:
    Queue()
    {
        front = rear = -1;
        size = 0;
    }

    void push(int val)
    {
        if (size >= 4)
        {
            cout << "Queue Overflow!\n";
            return;
        }

        if (rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % 4; // circular increment
        }
        q[rear] = val;
        size++;
        cout << val << " enqueued\n";
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << q[front] << endl;
        front = (front + 1) % 4;
        size--;
    }

    int peek()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return q[front];
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue (front → rear): ";
        for (int i = 0; i < size; i++)
            cout << q[(front + i) % 4] << " ";
        cout << "\n";
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    cout << "Front: " << q.peek() << "\n";

    q.pop();
    q.display();

    q.push(40);
    q.display();

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();

    return 0;
}