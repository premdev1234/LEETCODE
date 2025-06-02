class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row, column, and 3x3 box check
        for (int i = 0; i < 9; ++i) {
            vector<bool> rowCheck(9, false);
            vector<bool> colCheck(9, false);
            vector<bool> boxCheck(9, false);
            
            for (int j = 0; j < 9; ++j) {
                // Row check
                if (board[i][j] != '.') {
                    int idx = board[i][j] - '1';
                    if (rowCheck[idx]) return false;
                    rowCheck[idx] = true;
                }

                // Column check
                if (board[j][i] != '.') {
                    int idx = board[j][i] - '1';
                    if (colCheck[idx]) return false;
                    colCheck[idx] = true;
                }

                // 3x3 box check
                int row = 3 * (i / 3) + (j / 3);
                int col = 3 * (i % 3) + (j % 3);
                if (board[row][col] != '.') {
                    int idx = board[row][col] - '1';
                    if (boxCheck[idx]) return false;
                    boxCheck[idx] = true;
                }
            }
        }
        return true;
    }
};
