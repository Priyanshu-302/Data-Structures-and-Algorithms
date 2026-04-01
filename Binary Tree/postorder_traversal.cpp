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

void postorderTraversal(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    postorderTraversal(root);

    return 0;
}