class Solution {
public:
    static constexpr int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    int greedyDFS(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
            return 0;

        int current = grid[x][y];
        grid[x][y] = 0; // mark visited
        int max_gold = 0;

        for (auto& [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            max_gold = max(max_gold, greedyDFS(nx, ny, grid));
        }

        grid[x][y] = current; // backtrack
        return current + max_gold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int max_gold = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] > 0)
                    max_gold = max(max_gold, greedyDFS(i, j, grid));
        return max_gold;
    }
};
