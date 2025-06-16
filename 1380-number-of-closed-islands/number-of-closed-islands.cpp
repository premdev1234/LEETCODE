class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        // Flood-fill border 0s to 1s (not part of closed islands)
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) q.push({i, 0});
            if(grid[i][n - 1] == 0) q.push({i, n - 1});
        }
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 0) q.push({0, j});
            if(grid[m - 1][j] == 0) q.push({m - 1, j});
        }

        vector<int> dir = {0, -1, 0, 1, 0};
        while(!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            grid[i][j] = 1;
            for(int k = 0; k < 4; k++) {
                int ni = i + dir[k];
                int nj = j + dir[k + 1];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                    q.push({ni, nj});
                    grid[ni][nj] = 1;
                }
            }
        }

        // Now count the number of closed islands using BFS/DFS
        int ans = 0;
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    queue<pair<int,int>> q2;
                    q2.push({i,j});
                    grid[i][j] = 1;
                    while(!q2.empty()) {
                        auto [x,y] = q2.front(); q2.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = x + dir[k];
                            int ny = y + dir[k + 1];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                                q2.push({nx, ny});
                                grid[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
