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

class Codec
{
public:
    void serializeHelper(TreeNode *root, string &res)
    {
        if (root == nullptr)
        {
            res += "N ";
            return;
        }

        res += to_string(root->val) + " ";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        serializeHelper(root, res);
        return res;
    }

    TreeNode *deserializeHelper(vector<string> &nodes, int &i)
    {
        if (nodes[i] == "N")
        {
            i++;
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(nodes[i++]));

        root->left = deserializeHelper(nodes, i);
        root->right = deserializeHelper(nodes, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> nodes;
        stringstream ss(data);
        string temp;

        while (ss >> temp)
        {
            nodes.push_back(temp);
        }

        int i = 0;
        return deserializeHelper(nodes, i);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    TreeNode *deserialized = codec.deserialize(serialized);
    cout << "Deserialized Tree: ";
    if (deserialized != nullptr)
    {
        cout << deserialized->val << " ";
        if (deserialized->left != nullptr)
        {
            cout << deserialized->left->val << " ";
        }
        if (deserialized->right != nullptr)
        {
            cout << deserialized->right->val << " ";
        }
    }
    cout << endl;

    return 0;
}