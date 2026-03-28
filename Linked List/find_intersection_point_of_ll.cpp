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
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *t1 = headA;
        ListNode *t2 = headB;

        while (t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;

            if (t1 == t2)
                return t1;
            if (t1 == nullptr)
                t1 = headB;
            if (t2 == nullptr)
                t2 = headA;
        }

        return t1;
    }
};

int main()
{
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(7);
    headB->next->next->next = headA->next->next;
    Solution s;
    headA = s.getIntersectionNode(headA, headB);
    while (headA != nullptr)
    {
        cout << headA->val << " ";
        headA = headA->next;
    }
    return 0;
}