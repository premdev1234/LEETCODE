class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m + 1, INT_MIN);

        for (int i = 1; i <= n; i++) {
            int prev_diag = INT_MIN, prev_j = INT_MIN; // Track previous row values
            
            for (int j = 1; j <= m; j++) {
                int curr_j_minus_1 = dp[j];  // Store current dp[j] before updating
                
                // Compute max dot product for (i, j)
                int take = nums1[i - 1] * nums2[j - 1] + max(0, prev_diag);
                dp[j] = max({take, prev_j, dp[j]});
                
                // Update values for next iteration
                prev_diag = curr_j_minus_1;
                prev_j = dp[j];
            }
        }
        return dp[m];
    }
};
