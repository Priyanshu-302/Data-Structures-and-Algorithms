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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> ans(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int index = (flag) ? i : (n - 1 - i);

                ans[index] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            flag = !flag;
            result.push_back(ans);
        }

        return result;
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
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto &level : result)
    {
        for (int num : level)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}