class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            int currEffort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return currEffort;

            // Up
            if (row - 1 >= 0)
            {
                int newEffort = max(currEffort, abs(heights[row][col] - heights[row - 1][col]));

                // Edge Relaxation
                if (dist[row - 1][col] > newEffort)
                {
                    dist[row - 1][col] = newEffort;
                    pq.push({newEffort, {row - 1, col}});
                }
            }

            // Right
            if (col + 1 < m)
            {
                int newEffort = max(currEffort, abs(heights[row][col] - heights[row][col + 1]));

                // Edge Rexlaxation
                if (dist[row][col + 1] > newEffort)
                {
                    dist[row][col + 1] = newEffort;
                    pq.push({newEffort, {row, col + 1}});
                }
            }

            // Down
            if (row + 1 < n)
            {
                int newEffort = max(currEffort, abs(heights[row][col] - heights[row + 1][col]));

                // Edge Relaxation
                if (dist[row + 1][col] > newEffort)
                {
                    dist[row + 1][col] = newEffort;
                    pq.push({newEffort, {row + 1, col}});
                }
            }

            // Left
            if (col - 1 >= 0)
            {
                int newEffort = max(currEffort, abs(heights[row][col] - heights[row][col - 1]));

                // Edge Rexlaxation
                if (dist[row][col - 1] > newEffort)
                {
                    dist[row][col - 1] = newEffort;
                    pq.push({newEffort, {row, col - 1}});
                }
            }
        }

        return 0;
    }
};