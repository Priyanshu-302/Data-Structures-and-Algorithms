#include <bits/stdc++.h>
using namespace std;

// Node is defined as
class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *segregate(Node *head)
    {
        if (!head || !head->next)
            return head;

        Node *zeroDummy = new Node(0);
        Node *oneDummy = new Node(0);
        Node *twoDummy = new Node(0);

        Node *zero = zeroDummy;
        Node *one = oneDummy;
        Node *two = twoDummy;

        Node *temp = head;
        while (temp)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else if (temp->data == 2)
            {
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        zero->next = (oneDummy->next) ? oneDummy->next : twoDummy->next;
        one->next = twoDummy->next;
        two->next = nullptr;

        Node *newHead = zeroDummy->next;

        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;

        return newHead;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    Solution s;
    head = s.segregate(head);
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}