class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adj[u].push_back({v, price});
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;
        pq.push({0, {src, 0}}); // {price, {node, stops}}

        while (!pq.empty())
        {
            int price = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;
            pq.pop();

            if (node == dst)
                return price;

            if (stops == k + 1)
                continue;

            for (auto &it : adj[node])
            {
                int currNode = it.first;
                int currPrice = it.second;

                // Edge Relaxation
                if (dist[currNode][stops + 1] > price + currPrice)
                {
                    dist[currNode][stops + 1] = price + currPrice;
                    pq.push({price + currPrice, {currNode, stops + 1}});
                }
            }
        }

        return -1;
    }
};