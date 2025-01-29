class Solution {
public:
    int maxCoins(vector<int>& nums) {
        {
    int n = nums.size();
    // Add 1s to the beginning and end to handle boundary cases
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    // dp[i][j] stores the maximum coins obtained by bursting balloons from i to j (exclusive)
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // Iterate through different lengths of subarrays
    for (int len = 1; len <= n; ++len) {
        // Iterate through different starting positions
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            // Iterate through possible last balloons to burst in the subarray [i, j]
            for (int k = i; k <= j; ++k) {
                // Calculate coins obtained by bursting balloon k last
                int coins = nums[i - 1] * nums[k] * nums[j + 1];
                // Add coins from left and right subproblems
                coins += dp[i][k - 1] + dp[k + 1][j];
                // Update dp[i][j] if the current arrangement yields more coins
                dp[i][j] = max(dp[i][j], coins);
            }
        }
    }

    // The result is stored in dp[1][n], representing bursting balloons from 1 to n (exclusive)
    return dp[1][n];
}
    }
};