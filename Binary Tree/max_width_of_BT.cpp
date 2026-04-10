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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty())
        {
            int n = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;
            maxWidth = max(maxWidth, (int)(end - start + 1));
            for (int i = 0; i < n; i++)
            {
                auto node = q.front();
                q.pop();
                if (node.first->left)
                    q.push({node.first->left, node.second * 2 + 1});
                if (node.first->right)
                    q.push({node.first->right, node.second * 2 + 2});
            }
        }

        return maxWidth;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution solution;
    int maxWidth = solution.widthOfBinaryTree(root);

    cout << "Maximum Width of the Binary Tree: " << maxWidth << endl;

    return 0;
}