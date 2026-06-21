class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while (!pq.empty())
        {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == n - 1)
                return time;

            if (time > dist[row][col])
                continue;

            // UP
            if (row - 1 >= 0)
            {
                int newTime = max(time, grid[row - 1][col]);

                // Edge Relaxation
                if (dist[row - 1][col] > newTime)
                {
                    dist[row - 1][col] = newTime;
                    pq.push({newTime, {row - 1, col}});
                }
            }

            // RIGHT
            if (col + 1 < n)
            {
                int newTime = max(time, grid[row][col + 1]);

                // Edge Relaxation
                if (dist[row][col + 1] > newTime)
                {
                    dist[row][col + 1] = newTime;
                    pq.push({newTime, {row, col + 1}});
                }
            }

            // DOWN
            if (row + 1 < n)
            {
                int newTime = max(time, grid[row + 1][col]);

                // Edge Relaxation
                if (dist[row + 1][col] > newTime)
                {
                    dist[row + 1][col] = newTime;
                    pq.push({newTime, {row + 1, col}});
                }
            }

            // LEFT
            if (col - 1 >= 0)
            {
                int newTime = max(time, grid[row][col - 1]);

                // Edge Relaxation
                if (dist[row][col - 1] > newTime)
                {
                    dist[row][col - 1] = newTime;
                    pq.push({newTime, {row, col - 1}});
                }
            }
        }

        return -1;
    }
};