class Solution {
public:
    constexpr static int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool is_valid(int x, int y, int rows, int cols, vector<vector<int>>& grid) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0;
    }

    void floodfill(vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto &[dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (is_valid(nx, ny, rows, cols, grid)) {
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int num_island(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int regions = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 0) {
                    floodfill(grid, row, col);
                    regions++;
                }
            }
        }
        return regions;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> expanded_grid(3 * n, vector<int>(3 * n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch = grid[i][j];
                if (ch == '/') {
                    expanded_grid[3 * i][3 * j + 2] = 1;
                    expanded_grid[3 * i + 1][3 * j + 1] = 1;
                    expanded_grid[3 * i + 2][3 * j] = 1;
                } else if (ch == '\\') {
                    expanded_grid[3 * i][3 * j] = 1;
                    expanded_grid[3 * i + 1][3 * j + 1] = 1;
                    expanded_grid[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }

        return num_island(expanded_grid);
    }
};
