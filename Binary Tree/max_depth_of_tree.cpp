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
        int rh = checkDepth(root->right);

        return max(lh, rh) + 1;
    }

public:
    int maxDepth(TreeNode *root)
    {
        return checkDepth(root);
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
    int maxDepthValue = solution.maxDepth(root);

    cout << "Maximum Depth of the Binary Tree: " << maxDepthValue << endl;

    return 0;
}