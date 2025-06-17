class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size() , m = mat[0].size();
        // dp[0][0] = mat[0][0];
        for(int i = 1 ; i < n ; ++i) mat[i][0] += mat[i-1][0] ; 
        for(int i = 1 ; i < m ; ++i) mat[0][i] += mat[0][i-1] ; 
        for(int i = 1 ; i < n ; ++i) for(int j = 1 ; j < m ; j++)  mat[i][j] =  mat[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
        vector<vector<int>> res(n, vector<int>(m));

        // Use inclusion-exclusion to compute block sums
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int r1 = max(0, i - k), r2 = min(n - 1, i + k);
                int c1 = max(0, j - k), c2 = min(m - 1, j + k);

                int total = mat[r2][c2];
                if (r1 > 0) total -= mat[r1 - 1][c2];
                if (c1 > 0) total -= mat[r2][c1 - 1];
                if (r1 > 0 && c1 > 0) total += mat[r1 - 1][c1 - 1];

                res[i][j] = total;
            }
        }
        return move(res);
    }
};