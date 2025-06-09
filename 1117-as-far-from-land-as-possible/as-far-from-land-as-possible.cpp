class Solution {
public:
    static constexpr int directions[4][2] =  {{1,0},{-1,0},{0,1},{0,-1}};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = INT_MIN ;
        vector<bitset<100>> visited(n);
        queue<pair<int,int>> q ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] ==  1) {
                    q.push({i,j});
                    visited[i][j]  = 1 ;   
                }
            }
        }
        if (q.empty() || q.size() == n * n) return -1;
        int distance = -1;
        // Step 2: Standard BFS layer-wise
        while (!q.empty()) {
            int sz = q.size();
            ++distance; // increment distance level
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                        !visited[nx][ny] && grid[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return distance;
    }
};