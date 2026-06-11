class Solution
{
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &recPath, vector<int> &topo)
    {
        vis[node] = true;
        recPath[node] = true;

        for (int v : adj[node])
        {
            if (!vis[v])
            {
                if (dfs(v, adj, vis, recPath, topo))
                    return true;
            }
            else if (recPath[v])
                return true;
        }

        recPath[node] = false;
        topo.push_back(node);

        return false;
    }

public:
    string findOrder(vector<string> &words)
    {
        vector<vector<int>> adj(26);
        vector<bool> present(26, false);

        for (string &word : words)
        {
            for (char ch : word)
            {
                present[ch - 'a'] = true;
            }
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            string &s1 = words[i];
            string &s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            int j = 0;

            while (j < len && s1[j] == s2[j])
                j++;

            if (j == len && s1.size() > s2.size())
                return "";

            if (j < len)
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            }
        }

        vector<bool> vis(26, false);
        vector<bool> recPath(26, false);
        vector<int> topo;

        for (int i = 0; i < 26; i++)
        {
            if (present[i] && !vis[i])
            {
                if (dfs(i, adj, vis, recPath, topo))
                    return "";
            }
        }

        reverse(topo.begin(), topo.end());

        string ans;

        for (int node : topo)
        {
            ans.push_back(node + 'a');
        }

        return ans;
    }
};