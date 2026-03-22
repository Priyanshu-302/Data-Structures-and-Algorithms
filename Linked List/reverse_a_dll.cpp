#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *reverseDLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *last = nullptr;
    Node *curr = head;
    while (curr != nullptr)
    {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev;
    }

    return last->prev;
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head = reverseDLL(head);
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}