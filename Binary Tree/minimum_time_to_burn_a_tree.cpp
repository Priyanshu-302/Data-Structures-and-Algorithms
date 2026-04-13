#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    unordered_map<Node *, Node *> parent;

private:
    void markParent(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    Node *findTargetNode(Node *root, int target)
    {
        if (!root)
            return nullptr;
        if (root->data == target)
            return root;

        Node *left = findTargetNode(root->left, target);
        if (left)
            return left;

        return findTargetNode(root->right, target);
    }

public:
    int minTime(Node *root, int target)
    {
        markParent(root);

        Node *targetNode = findTargetNode(root, target);

        unordered_map<Node *, bool> vis;
        queue<Node *> q;
        q.push(targetNode);
        vis[targetNode] = true;

        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left] = true;
                    burned = true;
                }

                if (curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right] = true;
                    burned = true;
                }

                if (parent[curr] && !vis[parent[curr]])
                {
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                    burned = true;
                }
            }

            if (burned)
                time++;
        }

        return time;
    }
};