#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void preorderTraversal(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preorderTraversal(root);

    return 0;
}