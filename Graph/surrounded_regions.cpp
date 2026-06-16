class Solution
{
private:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();

        // Base Case
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' || vis[i][j])
            return;

        vis[i][j] = true;

        dfs(board, vis, i - 1, j); // top
        dfs(board, vis, i, j + 1); // right
        dfs(board, vis, i + 1, j); // bottom
        dfs(board, vis, i, j - 1); // left
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Check Boundaries
        // First Row
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O' && !vis[0][j])
            {
                dfs(board, vis, 0, j);
            }
        }

        // Last Row
        for (int j = 0; j < n; j++)
        {
            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
            {
                dfs(board, vis, m - 1, j);
            }
        }

        // First Column
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' && !vis[i][0])
            {
                dfs(board, vis, i, 0);
            }
        }

        // Last Column
        for (int i = 0; i < m; i++)
        {
            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
            {
                dfs(board, vis, i, n - 1);
            }
        }

        // Convert Remaining to X
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};