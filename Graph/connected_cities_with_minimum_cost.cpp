#include <bits/stdc++.h>
int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
    vector<vector<pair<int, int>>> adj(n + 1);

    // Adjacency List
    for (auto &conn : connections)
    {
        int u = conn[0];
        int v = conn[1];
        int wt = conn[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(n + 1, false);

    int minCost = 0;
    int cnt = 0;

    if (n == 1)
        return 0;

    pq.push({0, 1});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node])
            continue;

        minCost += cost;
        cnt++;
        vis[node] = true;

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (!vis[adjNode])
            {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return (cnt != n) ? -1 : minCost;
}