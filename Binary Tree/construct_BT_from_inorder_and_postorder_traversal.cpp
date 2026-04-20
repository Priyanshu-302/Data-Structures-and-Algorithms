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
    int idx;

    TreeNode *solve(int left, int right, vector<int> &postorder)
    {
        if (right < left)
            return nullptr;

        int rootVal = postorder[idx--];
        TreeNode *root = new TreeNode(rootVal);

        int pos = mpp[rootVal];

        root->right = solve(pos + 1, right, postorder);
        root->left = solve(left, pos - 1, postorder);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        idx = inorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        return solve(0, inorder.size() - 1, postorder);
    }
};

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution solution;
    TreeNode *root = solution.buildTree(inorder, postorder);

    return 0;
}