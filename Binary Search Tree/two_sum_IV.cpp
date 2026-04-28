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
    unordered_map<int, int> mpp;

public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        int first = root->val;
        int second = k - first;

        if (mpp.find(second) != mpp.end())
            return true;
        mpp[first]++;

        return findTarget(root->left, k) || findTarget(root->right, k);
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
    cout << solution.findTarget(root, 9) << endl;

    return 0;
}