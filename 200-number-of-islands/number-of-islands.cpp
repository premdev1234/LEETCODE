class Solution {
public:
    static constexpr int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(int x, int y, vector<vector<char>>& grid, int rows, int cols) {
        if (x >= rows or x < 0 or y >= cols or y < 0 or grid[x][y] == 'v' or
            grid[x][y] == '0')
            return;
        grid[x][y] = 'v';
        for (auto& [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            dfs(nx, ny, grid, rows, cols);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int islands = 0;
        for (int i = 0; i < n; ++i) {
            {
                for (int j = 0; j < m; ++j)
                    if (grid[i][j] == '1') {
                        dfs(i, j, grid, n, m);
                        islands++;
                    }
            }
        }
        return islands;
    }
};