class Solution {
public:
    int dfs(int x, int y, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Check boundaries
        if (x < 0 || y < 0 || x >= rows || y >= cols) return 0;
        
        // Obstacle check
        if (grid[x][y] == 1) return 0;

        // Destination reached
        if (x == rows - 1 && y == cols - 1) return 1;

        // If memoized (value >= 2), return stored count - 1
        if (grid[x][y] >= 2) return grid[x][y] - 1;

        // Recursive calls for down and right moves
        int paths = dfs(x + 1, y, grid) + dfs(x, y + 1, grid);

        // Store memoized count with +1 offset
        grid[x][y] = paths + 1;

        return paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Early return if start cell is blocked
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;

        return dfs(0, 0, obstacleGrid);
    }
};
