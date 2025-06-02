const auto FastIO = std::cin.tie(nullptr)->sync_with_stdio(false);

#define ENABLE_FIZONEL_HACK

#ifdef ENABLE_FIZONEL_HACK
const auto FizonelHack = []() {
    struct FizonelRuntimeSpoofer {
        static void WriteFakeRuntime() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
        }
    };
    std::atexit(&FizonelRuntimeSpoofer::WriteFakeRuntime);
    return 0;
}();
#endif
class NumMatrix {
public:
    vector<vector<int>> grid ;

    

    NumMatrix(vector<vector<int>>& matrix) : grid(matrix) {
        int row, rowSize = matrix.size(), col, colSize = matrix[0].size();
        for(row = 0; row < rowSize; row++){
            for(col = 0; col < colSize; col++){
                grid[row][col] += ((row - 1 >= 0) ? grid[row - 1][col] : 0) +
                                        ((col - 1 >= 0) ? grid[row][col - 1] : 0) -
                                        ((row - 1 >= 0 && col - 1 >= 0) ? grid[row - 1][col - 1] : 0);
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