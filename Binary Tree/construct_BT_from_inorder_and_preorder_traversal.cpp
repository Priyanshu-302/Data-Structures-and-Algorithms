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
    unordered_map<int, int> mpp;
    int idx = 0;

    TreeNode *solve(vector<int> &preorder, int left, int right)
    {
        if (left > right)
            return nullptr;

        int rootVal = preorder[idx++];
        TreeNode *root = new TreeNode(rootVal);

        int pos = mpp[rootVal];

        root->left = solve(preorder, left, pos - 1);
        root->right = solve(preorder, pos + 1, right);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        return solve(preorder, 0, inorder.size() - 1);
    }
};

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);

    return 0;
}