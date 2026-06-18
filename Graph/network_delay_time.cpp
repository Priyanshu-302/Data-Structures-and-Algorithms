class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adj[u].push_back({v, time});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node])
                continue;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeTime = it.second;

                // Edge Relaxation
                if (dist[adjNode] > dist[node] + edgeTime)
                {
                    dist[adjNode] = dist[node] + edgeTime;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxVal = 0;

        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;

            maxVal = max(maxVal, dist[i]);
        }

        return maxVal;
    }
};