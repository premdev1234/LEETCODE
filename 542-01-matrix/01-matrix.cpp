class Solution {
public:
    // Directions: down, right, up, left
    const vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        // Start BFS from all 0s (multi-source BFS)
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                // Valid cell and not visited
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                }
            }
        }

        return dist;
    }
};
