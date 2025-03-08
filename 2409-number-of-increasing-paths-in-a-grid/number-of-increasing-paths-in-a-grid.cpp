class Solution {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));
        
        // Compute the number of increasing paths from each cell
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = (result + dfs(grid, i, j)) % MOD;
            }
        }
        return result;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        
        int m = grid.size(), n = grid[0].size();
        dp[i][j] = 1; // Each cell itself is a valid path
        
        for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > grid[i][j]) {
                dp[i][j] = (dp[i][j] + dfs(grid, x, y)) % MOD;
            }
        }
        return dp[i][j];
    }
};
