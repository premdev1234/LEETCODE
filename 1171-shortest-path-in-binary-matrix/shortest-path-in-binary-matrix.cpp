class Solution {
public:
    static constexpr int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});  // (x, y, path length)

        while (!q.empty()) {
            auto [x, y, path] = q.front(); q.pop();

            // Reached destination
            if (x == n - 1 && y == m - 1)
                return path;

            // Mark as visited
            grid[x][y] = 1;

            for (auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                    q.push({nx, ny, path + 1});
                    grid[nx][ny] = 1;  // Mark early to avoid revisiting
                }
            }
        }
        return -1;  // No path found
    }
};
