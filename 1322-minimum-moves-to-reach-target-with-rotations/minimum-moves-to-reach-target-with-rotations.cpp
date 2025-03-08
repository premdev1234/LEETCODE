class Solution {
    enum Orientation { RIGHT = 0, DOWN = 1 };

    struct State {
        int dir, r, c, dist;
    };

public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<bool>>> vis(2, vector<vector<bool>>(n, vector<bool>(n, false)));
        deque<State> q;

        // Start from the initial position: RIGHT orientation at (0,1) with distance 0
        q.push_back({RIGHT, 0, 1, 0});
        vis[RIGHT][0][1] = true;

        while (!q.empty()) {
            State curr = q.front();
            q.pop_front();

            int direction = curr.dir, r = curr.r, c = curr.c, dist = curr.dist;

            // If reached target (n-1, n-1) in RIGHT orientation
            if (direction == RIGHT && r == n - 1 && c == n - 1) return dist;

            // Move Right
            if (direction == RIGHT && c + 1 < n && grid[r][c + 1] == 0 && !vis[RIGHT][r][c + 1]) {
                vis[RIGHT][r][c + 1] = true;
                q.push_back({RIGHT, r, c + 1, dist + 1});
            }

            // Move Down
            if (direction == DOWN && r + 1 < n && grid[r + 1][c] == 0 && !vis[DOWN][r + 1][c]) {
                vis[DOWN][r + 1][c] = true;
                q.push_back({DOWN, r + 1, c, dist + 1});
            }

            // Rotate Clockwise (Horizontal → Vertical)
            if (direction == RIGHT && r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c - 1] == 0 && !vis[DOWN][r + 1][c - 1]) {
                vis[DOWN][r + 1][c - 1] = true;
                q.push_back({DOWN, r + 1, c - 1, dist + 1});
            }

            // Rotate Counterclockwise (Vertical → Horizontal)
            if (direction == DOWN && c + 1 < n && grid[r][c + 1] == 0 && grid[r - 1][c + 1] == 0 && !vis[RIGHT][r - 1][c + 1]) {
                vis[RIGHT][r - 1][c + 1] = true;
                q.push_back({RIGHT, r - 1, c + 1, dist + 1});
            }

            // Move Down (Horizontal Snake)
            if (direction == RIGHT && r + 1 < n && grid[r + 1][c] == 0 && grid[r + 1][c - 1] == 0 && !vis[RIGHT][r + 1][c]) {
                vis[RIGHT][r + 1][c] = true;
                q.push_back({RIGHT, r + 1, c, dist + 1});
            }

            // Move Right (Vertical Snake)
            if (direction == DOWN && c + 1 < n && grid[r][c + 1] == 0 && grid[r - 1][c + 1] == 0 && !vis[DOWN][r][c + 1]) {
                vis[DOWN][r][c + 1] = true;
                q.push_back({DOWN, r, c + 1, dist + 1});
            }
        }
        return -1;
    }
};
