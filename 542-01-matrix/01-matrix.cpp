class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Step 1: Replace non-zero cells with a large number (to represent infinity)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != 0) mat[i][j] = INT_MAX - 1; // avoid overflow
            }
        }

        // Step 2: First pass (top-left to bottom-right)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) mat[i][j] = min(mat[i][j], mat[i-1][j] + 1);
                if (j > 0) mat[i][j] = min(mat[i][j], mat[i][j-1] + 1);
            }
        }

        // Step 3: Second pass (bottom-right to top-left)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) mat[i][j] = min(mat[i][j], mat[i+1][j] + 1);
                if (j < n - 1) mat[i][j] = min(mat[i][j], mat[i][j+1] + 1);
            }
        }

        return move(mat);
    }
};
