class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    int totalSum = accumulate(rods.begin(), rods.end(), 0);
    vector<int> dp(totalSum + 1, -1);
    dp[0] = 0;

    for (int rod : rods) {
      vector<int> oldDp = dp;
      for (int diff = 0; diff <= totalSum - rod; ++diff) {
        if (oldDp[diff] < 0) continue;

        // Add to left pole
        dp[diff + rod] = max(dp[diff + rod], oldDp[diff]);

        // Add to right pole
        int newDiff = abs(diff - rod);
        int newShorter = oldDp[diff] + min(diff, rod);
        dp[newDiff] = max(dp[newDiff], newShorter);
      }
    }
    return dp[0];
  }
};
