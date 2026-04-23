#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    int findCeil(Node *root, int x)
    {
        int ceil = -1;

        while (root != nullptr)
        {
            if (root->data == x)
                return root->data;

            else if (x < root->data)
            {
                ceil = root->data;
                root = root->left;
            }
            else
                root = root->right;
        }

        return ceil;
    }
};

int main()
{
    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(10);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->right = new Node(1);

    Solution sol;
    cout << sol.findCeil(root, 6) << endl;
    return 0;
}