#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Brute Force
        // ListNode* temp = head;
        // stack<int> st;

        // while (temp != nullptr) {
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;
        // while (temp != nullptr) {
        //     temp->val = st.top();
        //     st.pop();
        //     temp = temp->next;
        // }

        // return head;

        // Optimal
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next; // temp = a;
            curr->next = prev; // a = b;
            prev = curr; // b = temp;

            curr = next;
        }

        return prev;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3); 
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    head = s.reverseList(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}