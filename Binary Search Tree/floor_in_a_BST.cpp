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
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int findMaxFork(Node *root, int k)
    {
        int ceil = -1;

        while (root != nullptr)
        {
            if (root->data == k)
                return root->data;
            else if (root->data < k)
            {
                ceil = root->data;
                root = root->right;
            }
            else
                root = root->left;
        }

        return ceil;
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
    cout << sol.findMaxFork(root, 4) << endl;
    return 0;
}