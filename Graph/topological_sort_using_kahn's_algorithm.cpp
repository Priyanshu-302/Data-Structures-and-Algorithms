vector<int> topoSort(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    vector<int> indegree(V, 0);
    vector<int> topo;

    // Calculate indegree of all nodes
    for (int i = 0; i < V; i++)
    {
        for (auto v : adj[i])
        {
            indegree[v]++;
        }
    }

    queue<int> q;

    // Push all the indegrees with value 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (auto v : adj[node])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    return topo;
}