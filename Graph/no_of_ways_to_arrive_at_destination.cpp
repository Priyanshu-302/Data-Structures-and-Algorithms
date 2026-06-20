class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        for (auto &road : roads)
        {
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            long long currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &it : adj[node])
            {
                int newDist = it.second;
                int currNode = it.first;

                // Edge Relaxation
                if (dist[currNode] > currDist + newDist)
                {
                    dist[currNode] = currDist + newDist;
                    pq.push({currDist + newDist, currNode});
                    ways[currNode] = ways[node];
                }
                else if (currDist + newDist == dist[currNode])
                {
                    ways[currNode] = (ways[currNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};