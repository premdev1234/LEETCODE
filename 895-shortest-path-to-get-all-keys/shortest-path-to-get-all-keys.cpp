class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int allKeys = 0;
        int startX = 0, startY = 0;
 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    startX = i;
                    startY = j;
                } else if (islower(c)) {
                    allKeys |= (1 << (c - 'a'));
                }
            }
        }
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << 6, false)));
        queue<tuple<int, int, int>> q;
        q.push({startX, startY, 0});
        visited[startX][startY][0] = true;
        int steps = 0;
        
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y, keys] = q.front();
                q.pop();
                
                if (keys == allKeys) {
                    return steps;
                }
                
                for (auto& d : directions) {
                    int nx = x + d[0], ny = y + d[1];
                    int newKeys = keys;
                    
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    char cell = grid[nx][ny];
                    if (cell == '#') continue;
                    
                    if (islower(cell))
                        newKeys |= (1 << (cell - 'a'));
                    
                    if (isupper(cell) && ((keys & (1 << (cell - 'A'))) == 0))
                        continue;
                    
                    if (!visited[nx][ny][newKeys]) {
                        visited[nx][ny][newKeys] = true;
                        q.push({nx, ny, newKeys});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
