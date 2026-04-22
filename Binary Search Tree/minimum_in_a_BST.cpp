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
    int minValue(Node *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->data;
        while (root->left != nullptr)
            root = root->left;
        return root->data;
    }
};

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution sol;
    cout << sol.minValue(root) << endl;

    return 0;
}