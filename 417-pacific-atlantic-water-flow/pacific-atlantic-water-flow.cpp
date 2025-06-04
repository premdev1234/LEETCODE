class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    static constexpr int MAX_M = 200;

    void dfs(int i, int j, vector<vector<int>>& heights, vector<bitset<MAX_M>>& ocean) {
        ocean[i][j] = true;
        for (auto& dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                !ocean[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(ni, nj, heights, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<bitset<MAX_M>> pacific(n), atlantic(n);

        for (int i = 0; i < n; ++i) dfs(i, 0, heights, pacific);
        for (int j = 0; j < m; ++j) dfs(0, j, heights, pacific);

        for (int i = 0; i < n; ++i) dfs(i, m - 1, heights, atlantic);
        for (int j = 0; j < m; ++j) dfs(n - 1, j, heights, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
