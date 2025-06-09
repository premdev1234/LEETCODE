class Solution {
public:
    const vector<pair<int, int>> knightMoves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    double knightProbability(int n, int totalMoves, int rows, int cols) {
        // dp[k][i][j] = probability to be on cell (i, j) after k moves
        vector<vector<vector<double>>> dp(totalMoves + 1, vector<vector<double>>(n, vector<double>(n, 0.0)));
        dp[0][rows][cols] = 1.0;

        for (int move = 1; move <= totalMoves; ++move) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (const auto& [dx, dy] : knightMoves) {
                        int prevX = i + dx;
                        int prevY = j + dy;
                        if (prevX >= 0 && prevX < n && prevY >= 0 && prevY < n) {
                            dp[move][i][j] += dp[move - 1][prevX][prevY] / 8.0;
                        }
                    }
                }
            }
        }

        // Sum all probabilities after k moves
        double totalProbability = 0.0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                totalProbability += dp[totalMoves][i][j];

        return totalProbability;
    }
};
