class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> time(n, vector<int>(m, 0));

        int fresh = 0;

        // Step 1: Push all rotten oranges into queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    ++fresh;
            }
        }

        int ans = 0;
        int dirs[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto &[dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    time[nx][ny] = time[x][y] + 1;
                    ans = max(ans, time[nx][ny]);
                    q.push({nx, ny});
                    --fresh;
                }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};
