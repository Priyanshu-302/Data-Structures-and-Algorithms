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
    int res = -1;

private:
    void inorder(TreeNode *root, int &k)
    {
        if (!root || k == 0)
            return;
        inorder(root->left, k);
        k--;

        if (k == 0)
        {
            res = root->val;
            return;
        }

        inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return res;
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
    cout << solution.kthSmallest(root, 3) << endl;

    return 0;
}