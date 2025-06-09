class Solution {
public:
    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int x, int y, vector<vector<char>>& board, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') return;

        board[x][y] = 'T'; // Temporarily mark as safe

        for (const auto& [dx, dy] : directions) {
            dfs(x + dx, y + dy, board, n, m);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        if (n == 0 || m == 0) return;

        // Step 1: DFS from border 'O's
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board, n, m);       // Left border
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board, n, m); // Right border
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board, n, m);       // Top border
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board, n, m); // Bottom border
        }

        // Step 2: Final board update
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';       // Captured region
                else if (board[i][j] == 'T') board[i][j] = 'O';  // Restore safe region
            }
        }
    }
};
