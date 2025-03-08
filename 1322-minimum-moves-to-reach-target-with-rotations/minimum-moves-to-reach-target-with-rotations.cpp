class Solution {
    enum Orientation {
        RIGHT = 0,
        DOWN = 1
    };
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        bool vis[2][n][n];
        memset(vis, false, sizeof(vis));
        queue<array<int, 4>> q;
        q.push({RIGHT, 0, 1, 0});
        vis[RIGHT][0][1] = true;
        while (!q.empty()) {
            auto [direction, r, c, dist] = q.front();
            q.pop();
            if (direction == RIGHT && r == n - 1 && c == n - 1) return dist;
            switch (direction) {
                case RIGHT:
                    if (c + 1 < n && !vis[RIGHT][r][c + 1] && grid[r][c + 1] == 0) {
                        vis[RIGHT][r][c + 1] = true;
                        q.push({RIGHT, r, c + 1, dist + 1});
                    }
                    if (r + 1 < n && grid[r + 1][c] + grid[r + 1][c - 1] == 0) {
                        if (!vis[RIGHT][r + 1][c]) {
                            vis[RIGHT][r + 1][c] = true;
                            q.push({RIGHT, r + 1, c, dist + 1});
                        }
                        if (!vis[DOWN][r + 1][c - 1]) {
                            vis[DOWN][r + 1][c - 1] = true;
                            q.push({DOWN, r + 1, c - 1, dist + 1});
                        }
                    }
                    break;
                case DOWN:
                    if (r + 1 < n && !vis[DOWN][r + 1][c] && grid[r + 1][c] == 0) {
                        vis[DOWN][r + 1][c] = true;
                        q.push({DOWN, r + 1, c, dist + 1});
                    }
                    if (c + 1 < n && grid[r][c + 1] + grid[r - 1][c + 1] == 0) {
                        if (!vis[DOWN][r][c + 1]) {
                            vis[DOWN][r][c + 1] = true;
                            q.push({DOWN, r, c + 1, dist + 1});
                        }
                        if (!vis[RIGHT][r - 1][c + 1]) {
                            vis[RIGHT][r - 1][c + 1] = true;
                            q.push({RIGHT, r - 1, c + 1, dist + 1});
                        }
                    }
                    break;
                default:
                    // Do nothing
            };
        }
        return -1;
    }
}; 