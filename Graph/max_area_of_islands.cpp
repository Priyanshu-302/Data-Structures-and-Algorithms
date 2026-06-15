class Solution
{
private:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Base Case
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || vis[i][j])
            return 0;

        vis[i][j] = true;

        int area = 1;

        area += dfs(grid, vis, i - 1, j); // top
        area += dfs(grid, vis, i, j + 1); // right
        area += dfs(grid, vis, i + 1, j); // bottom
        area += dfs(grid, vis, i, j - 1); // left

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int maxArea = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    int area = dfs(grid, vis, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};