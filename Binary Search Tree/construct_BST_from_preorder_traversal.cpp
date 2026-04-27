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
    int i = 0;

private:
    TreeNode *isValid(vector<int> &preorder, int minVal = INT_MIN, int maxVal = INT_MAX)
    {
        if (i >= preorder.size())
            return nullptr;
        if (preorder[i] < minVal || preorder[i] > maxVal)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = isValid(preorder, minVal, root->val);
        root->right = isValid(preorder, root->val, maxVal);

        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return isValid(preorder);
    }
};

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution solution;
    TreeNode *result = solution.bstFromPreorder(preorder);
    cout << result->val << endl;
    return 0;
}