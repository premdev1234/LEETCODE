class Solution {
public:
    int n;
    vector<int> dp;
    int dfs(int pos, int mask) {
        if (pos > n)return 1;
        if (dp[mask] != -1)return dp[mask];
        int ans = 0;
        for (int num = 1; num <= n; num++)if (!(mask & (1 << (num - 1))) &&(num % pos == 0 || pos % num == 0)) ans += dfs(pos + 1, mask | (1 << (num - 1)));
        return dp[mask] = ans;
    }
    int countArrangement(int N) {
        n = N;
        dp.assign(1 << n, -1);
        return dfs(1, 0);
    }
};