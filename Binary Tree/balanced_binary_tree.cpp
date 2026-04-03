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
private:
    int checkDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int lh = checkDepth(root->left);
        if (lh == -1)
            return -1;

        int rh = checkDepth(root->right);
        if (rh == -1)
            return -1;

        if (abs(rh - lh) > 1)
            return -1;

        return max(lh, rh) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return checkDepth(root) != -1;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    bool isBalancedTree = solution.isBalanced(root);

    cout << "Is the Binary Tree Balanced? " << (isBalancedTree ? "Yes" : "No") << endl;
    return 0;
}