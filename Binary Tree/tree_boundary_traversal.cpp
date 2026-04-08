#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    bool isLeaf(Node *root)
    {
        return (root->left == nullptr && root->right == nullptr);
    }

    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }

        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
    }

    void addReverseRightBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp;

        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            res.push_back(temp[i]);
        }
    }

public:
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> res;

        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addReverseRightBoundary(root, res);

        return res;
    }
};

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(55);
    root->right->right->left = new Node(60);
    root->right->right->left->left = new Node(57);

    Solution solution;
    vector<int> result = solution.boundaryTraversal(root);

    cout << "Boundary Traversal of the Binary Tree: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}