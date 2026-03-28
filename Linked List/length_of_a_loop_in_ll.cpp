#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int lengthOfLoop(Node *head)
    {
        if (!head)
            return 0;

        Node *slow = head;
        Node *fast = head;

        int cnt = 0;
        bool isCycle = false;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isCycle = true;
                break;
            }
        }

        if (isCycle)
        {
            cnt++;
            slow = slow->next;
            while (slow != fast)
            {
                cnt++;
                slow = slow->next;
            }
        }

        return cnt;
    }
};

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;
    Solution s;
    cout << s.lengthOfLoop(head);
    return 0;
}