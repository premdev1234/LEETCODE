class Solution {
public:
    long long dp[100005][2];

    long long solve(int i, int carry, vector<int>& nums, string& s) {
        if (i < 0) return 0;
        long long &ans = dp[i][carry];
        if (ans != -1) return ans;
        ans = 0;
        if (s[i] == '0') {
            ans = (carry ? nums[i] : 0) + solve(i - 1, 0, nums, s);
        } else {
            long long keep = nums[i] +solve(i - 1, 0, nums, s);
            long long move = (carry ? nums[i] : 0) + solve(i - 1, 1, nums, s);
            ans = max(keep, move);
        }

        return ans;
    }
    long long maxTotal(vector<int>& nums, string s) {
        memset(dp, -1, sizeof(dp));
        return solve((int)nums.size() - 1, 0, nums, s);
    }
};