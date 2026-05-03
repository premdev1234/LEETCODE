class Solution {
public:
    vector<vector<string>> res;
    void backtrack(int n, int row, int cols, int diag1, int diag2, vector<string>& board) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            int pos = available & -available;
            available -= pos;
            int col = __builtin_ctz(pos);
            board[row][col] = 'Q';
            backtrack(n,row + 1,cols | pos,(diag1 | pos) << 1,(diag2 | pos) >> 1,board);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(n, 0, 0, 0, 0, board);
        return res;
    }
};