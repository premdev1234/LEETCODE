class NumMatrix {
public:
    vector<vector<int>> grid ;

    

    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        grid.resize(n, vector<int>(m));  // resize all rows properly
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = matrix[i][j];
                if (i > 0) grid[i][j] += grid[i - 1][j];
                if (j > 0) grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];
            }
        }
    }
    
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long res = grid[row2][col2];
        if (row1 > 0) res -= grid[row1 - 1][col2];
        if (col1 > 0) res -= grid[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) res += grid[row1 - 1][col1 - 1];
        return res;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */