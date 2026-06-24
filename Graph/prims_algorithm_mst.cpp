class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(V, false);

        int sum = 0;

        pq.push({0, 0}); // {cost, node}

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = true;
            sum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (!vis[adjNode])
                {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return sum;
    }
};