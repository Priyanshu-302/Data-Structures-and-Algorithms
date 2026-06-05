class Solution
{
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[node] = true;
        recPath[node] = true;

        for (auto v : adj[node])
        {
            if (!vis[v])
            {
                if (dfs(v, adj, vis, recPath))
                    return true;
            }
            else if (recPath[v])
                return true;
        }

        recPath[node] = false;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, recPath))
                    return true;
            }
        }

        return false;
    }
};