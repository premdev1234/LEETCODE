class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;

        for (int rod : rods) {
            unordered_map<int, int> cur(dp);  // snapshot of current state

            for (auto [diff, smaller] : cur) {
                // 1. Add rod to left side (diff increases)
                int new_diff1 = diff + rod;
                dp[new_diff1] = max(dp[new_diff1], smaller);

                // 2. Add rod to right side (diff decreases or flips)
                int new_diff2 = abs(diff - rod);
                int new_smaller = smaller + min(rod, diff);
                dp[new_diff2] = max(dp[new_diff2], new_smaller);
            }
        }

        return dp[0]; // max height when difference is 0 (equal sides)
    }
};
