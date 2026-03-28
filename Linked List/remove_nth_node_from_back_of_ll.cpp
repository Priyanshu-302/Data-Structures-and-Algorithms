#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        head = reverse(head);
        int cnt = 0;

        if (n == 1)
        {
            ListNode *ptr = head;
            head = head->next;
            ptr->next = nullptr;
            delete ptr;
        }
        else
        {
            ListNode *temp = head;
            int cnt = 1;

            while (temp && cnt < n - 1)
            {
                temp = temp->next;
                cnt++;
            }

            if (temp && temp->next)
            {
                ListNode *del = temp->next;
                temp->next = temp->next->next;
                del->next = nullptr;
                delete del;
            }
        }

        return reverse(head);
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    head = s.removeNthFromEnd(head, 2);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}