class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &topo)
    {
        vis[node] = true;

        for (int v : adj[node])
        {
            if (!vis[v])
            {
                dfs(v, adj, vis, topo);
            }
        }

        topo.push_back(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<bool> vis(V, false);
        vector<int> topo;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, topo);
            }
        }

        reverse(topo.begin(), topo.end());

        return topo;
    }
};