class Solution {
private:
    int dp[101][1025];    
    int func(vector<vector<int>>& grid, int bitmask, int num, unordered_map<int, vector<int>>& mp) {
        if(num == 0)
            return 0;
        if(dp[num][bitmask] != -1)
            return dp[num][bitmask];

        int res = func(grid, bitmask, num-1, mp);

        for(auto row: mp[num]) {

            if(bitmask >> row & 1)
                continue;
            res = max(res, num + func(grid, (bitmask | (1<<row)), num-1, mp));
        }
        return dp[num][bitmask] = res;
    }

public:
    int maxScore(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        unordered_map<int, vector<int>> mp;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                mp[grid[i][j]].push_back(i);
            }
        }
        return func(grid, 0, 100, mp);
    }
};