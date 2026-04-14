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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        if (!root->left && !root->right)
            return root->val;

        queue<TreeNode *> q;
        q.push(root);

        int cnt = 0;

        while (!q.empty())
        {
            int size = q.size();
            cnt += size;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return cnt;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int nodeCount = solution.countNodes(root);

    cout << "Number of nodes in the binary tree: " << nodeCount << endl;

    return 0;
}