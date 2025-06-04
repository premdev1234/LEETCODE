class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));

        // Initialize dp for zero cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) dp[i][j] = 0;
            }
        }

        // First pass: top-left to bottom-right
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            }
        }

        // Second pass: bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                if (j < n - 1) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
            }
        }

        return dp;
    }
};
