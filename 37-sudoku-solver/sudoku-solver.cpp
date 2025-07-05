#define vvc vector<vector<char>>

class Solution {
public:
    bool is_safe(int i, int j, char val, vvc &board) {
        // Check row and column
        for (int r = 0; r < 9; ++r) {
            if (board[i][r] == val || board[r][j] == val) return false;
        }

        // Check 3x3 block
        int row_start = (i / 3) * 3;
        int col_start = (j / 3) * 3;
        for (int r = row_start; r < row_start + 3; ++r) {
            for (int c = col_start; c < col_start + 3; ++c) {
                if (board[r][c] == val) return false;
            }
        }
        return true;
    }

    bool solve(vvc &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; ++val) {
                        if (is_safe(i, j, val, board)) {
                            board[i][j] = val;
                            if (solve(board)) return true; // Move forward
                            board[i][j] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number, must backtrack
                }
            }
        }
        return true; // Solved
    }

    void solveSudoku(vvc &board) {
        solve(board);
    }
};
