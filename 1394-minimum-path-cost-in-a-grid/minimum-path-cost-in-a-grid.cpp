class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp = grid[0]; // cost to reach row 0 is just the cell value

        for (int row = 0; row < m - 1; ++row) {
            vector<int> new_dp(n, INT_MAX);
            for (int from = 0; from < n; ++from) {
                int from_val = grid[row][from];
                for (int to = 0; to < n; ++to) {
                    int cost = dp[from] + moveCost[from_val][to] + grid[row + 1][to];
                    new_dp[to] = min(new_dp[to], cost);
                }
            }
            dp = move(new_dp);
        }

        return *min_element(dp.begin(), dp.end());
    }
};
