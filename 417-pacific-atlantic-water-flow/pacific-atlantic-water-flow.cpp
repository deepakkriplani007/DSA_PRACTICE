class Solution {
public:
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        // run DFS from all Pacific-border and Atlantic-border cells
        for (int i = 0; i < n; ++i) {
            dfs(grid, pac, i, 0, -1);       // Pacific left
            dfs(grid, atl, i, m - 1, -1);   // Atlantic right
        }
        for (int j = 0; j < m; ++j) {
            dfs(grid, pac, 0, j, -1);       // Pacific top
            dfs(grid, atl, n - 1, j, -1);   // Atlantic bottom
        }

        // collect intersection points
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& ocean,
             int i, int j, int prevHeight) {
        // out of bounds or height restriction
        if (i < 0 || i >= n || j < 0 || j >= m || ocean[i][j] ||
            grid[i][j] < prevHeight)
            return;

        ocean[i][j] = true;

        dfs(grid, ocean, i + 1, j, grid[i][j]);
        dfs(grid, ocean, i - 1, j, grid[i][j]);
        dfs(grid, ocean, i, j + 1, grid[i][j]);
        dfs(grid, ocean, i, j - 1, grid[i][j]);
    }
};
