class Solution
{
private:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Base Case
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || vis[i][j])
            return;

        vis[i][j] = true;

        dfs(grid, vis, i - 1, j); // top
        dfs(grid, vis, i, j + 1); // right
        dfs(grid, vis, i + 1, j); // bottom
        dfs(grid, vis, i, j - 1); // left
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // First Row
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1 && !vis[0][j])
            {
                dfs(grid, vis, 0, j);
            }
        }

        // Last Row
        for (int j = 0; j < n; j++)
        {
            if (grid[m - 1][j] == 1 && !vis[m - 1][j])
            {
                dfs(grid, vis, m - 1, j);
            }
        }

        // First Column
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1 && !vis[i][0])
            {
                dfs(grid, vis, i, 0);
            }
        }

        // Last Row
        for (int i = 0; i < m; i++)
        {
            if (grid[i][n - 1] == 1 && !vis[i][n - 1])
            {
                dfs(grid, vis, i, n - 1);
            }
        }

        // Count the remaining
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    count++;
                }
            }
        }

        return count;
    }
};