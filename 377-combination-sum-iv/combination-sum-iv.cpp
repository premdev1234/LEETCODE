class Solution {
public:
    int combinationSum4(vector<int>& coins, int target) {
        using ll = __int128_t;
        const int n = coins.size();
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        sort(coins.begin(), coins.end()); // helpful if pruning

        for (int i = 1; i <= target; i++) {
            for (int coin : coins) {
                if (coin > i) break; // pruning
                if(i-coin >= 0 ) dp[i] += dp[i - coin];
            }
        }

        return dp[target] > INT_MAX ? -1 : static_cast<int>(dp[target]); // safe cast
    }
};
