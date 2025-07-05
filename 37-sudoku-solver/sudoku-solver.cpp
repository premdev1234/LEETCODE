#define vvc vector<vector<char>>

class Solution {
public:
    bool is_safe(vector<vector<char>>& board,char val,int row,int col){
        for(int i=0;i<9;i++){
            if(board[i][col]==val || board[row][i]==val){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }

    bool solve(vvc &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; ++val) {
                        if (is_safe(board,val,i, j)) {
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
