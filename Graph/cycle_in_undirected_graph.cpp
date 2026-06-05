class Solution {
  public:
    bool dfs(int node, int par, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;
        
        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                // if because if cycle exists forward not in the current traversal return true
                if (dfs(neighbour, node, vis, adj)) return true;
            } else if (neighbour != par) {
                return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build the adjacency list
        vector<vector<int>> adj(V);
        for (auto& u : edges) {
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        
        vector<bool> vis(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj)) return true;
            }
        }
        
        return false;
    }
};