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
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> res(2, nullptr);

        Node *predecessor = nullptr;
        Node *successor = nullptr;
        Node *curr = root;

        while (curr != nullptr)
        {
            if (curr->data < key)
            {
                predecessor = curr;
                curr = curr->right;
            }
            else if (curr->data > key)
            {
                successor = curr;
                curr = curr->left;
            }
            else
            {
                if (curr->left != nullptr)
                {
                    Node *temp = curr->left;
                    while (temp->right != nullptr)
                    {
                        temp = temp->right;
                    }
                    predecessor = temp;
                }

                if (curr->right != nullptr)
                {
                    Node *temp = curr->right;
                    while (temp->left != nullptr)
                        temp = temp->left;
                    successor = temp;
                }

                break;
            }
        }

        res[0] = predecessor;
        res[1] = successor;

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

    int pre, suc;
    cin >> pre >> suc;
    Solution s;
    vector<Node *> ptr = s.findPreSuc(root, pre);
    return 0;
}