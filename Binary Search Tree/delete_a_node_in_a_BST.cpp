#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // no left child
            if (!root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            // no right child
            else if (!root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // two children
            else
            {
                TreeNode *successor = root->right;
                while (successor->left != nullptr)
                {
                    successor = successor->left;
                }
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }

        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution solution;
    solution.deleteNode(root, 3);
    return 0;
}