class Solution
{
private:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;

        if (grid[i][j] == 0)
            return 1;

        if (vis[i][j])
            return 0;

        vis[i][j] = true;

        int perimeter = 0;

        perimeter += dfs(grid, vis, i - 1, j); // top
        perimeter += dfs(grid, vis, i, j + 1); // top
        perimeter += dfs(grid, vis, i + 1, j); // top
        perimeter += dfs(grid, vis, i, j - 1); // top

        return perimeter;
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return dfs(grid, vis, i, j);
            }
        }

        return 0;
    }
};