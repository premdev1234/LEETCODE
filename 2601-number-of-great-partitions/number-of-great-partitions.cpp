class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        
        if (totalSum < 2 * k) return 0;

        long long totalWays = 1;
        for (int i = 0; i < n; i++) totalWays = (totalWays * 2) % MOD;

        vector<int> dp(k, 0);
        dp[0] = 1;
        long long badWays = 0;

        for (int num : nums) {
            for (int j = k - 1; j >= num; j--) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }

        for (int i = 0; i < k; i++) badWays = (badWays + dp[i]) % MOD;

        return (totalWays - (2 * badWays) % MOD + MOD) % MOD;
    }
};
