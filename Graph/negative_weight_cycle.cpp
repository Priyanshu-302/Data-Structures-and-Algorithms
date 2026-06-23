class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> dist(n, 0);

        // Bellman ford implementtion
        for (int i = 0; i < n - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Negative cycle
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[v] > dist[u] + wt)
                return 1;
        }

        return 0;
    }
};