class Solution
{
private:
    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis,
             vector<bool> &recPath)
    {
        vis[node] = true;
        recPath[node] = true;

        for (int v : adj[node])
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (dfs(i, adj, vis, recPath))
                return false;
        }

        return true;
    }
};