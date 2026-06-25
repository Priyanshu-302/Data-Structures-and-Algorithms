class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;

        vector<bool> vis(n, false);

        int minCost = 0;
        int cnt = 0;

        pq.push({0, 0});

        while (!pq.empty() && cnt < n)
        {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = true;
            minCost += cost;
            cnt++;

            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);

                    pq.push({dist, i});
                }
            }
        }

        return minCost;
    }
};