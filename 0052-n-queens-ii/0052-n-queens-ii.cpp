class Solution {
public:
    int solve(int n, int row, int cols, int diag1, int diag2) {
        if (row == n) return 1;
        int count = 0;
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            int pos = available & -available;
            available -= pos;
            count += solve(n,row + 1,cols | pos,(diag1 | pos) << 1,(diag2 | pos) >> 1);
        }
        return count;
    }
    int totalNQueens(int n) {
        return solve(n,0,0,0,0);
    }
};