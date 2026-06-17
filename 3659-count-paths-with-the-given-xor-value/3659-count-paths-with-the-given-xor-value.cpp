class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    static constexpr int directions[2][2] = {{-1,0},{0,-1}};
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp( rows, vector<vector<int>>(cols, vector<int>(32, 0)));
        dp[0][0][grid[0][0]] = 1;
        for(int i = 1; i < cols; ++i){
            for(int j = 0; j < 32; ++j){
                if(dp[0][i - 1][j]) dp[0][i][j ^ grid[0][i]] = (dp[0][i][j ^ grid[0][i]] + dp[0][i - 1][j]) % mod;
            }
        }
        for(int i = 1; i < rows; ++i){
            for(int j = 0; j < 32; ++j){
                if(dp[i - 1][0][j]) dp[i][0][j ^ grid[i][0]] = (dp[i][0][j ^ grid[i][0]] + dp[i - 1][0][j]) % mod;
            }
        }
        for(int i = 1; i < rows; ++i){
            for(int j = 1; j < cols; ++j){
                for(int x = 0; x < 32; ++x){
                    for(auto &dir : directions){
                        int pi = i + dir[0] , pj = j + dir[1];
                        if(dp[pi][pj][x]) dp[i][j][x ^ grid[i][j]] = (dp[i][j][x ^ grid[i][j]] + dp[pi][pj][x]) % mod;
                    }
                }
            }
        }
        return dp[rows - 1][cols - 1][k];
    }
};