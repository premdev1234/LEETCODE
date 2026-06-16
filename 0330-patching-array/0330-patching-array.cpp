class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long num = 0;
        int ans = 0;
        int i = 0;

        while (num < n) {
            if (i < nums.size() && nums[i] <= num + 1) {
                num += nums[i];
                i++;
            } else {
                num += (num + 1);
                ans++;
            }
        }

        return ans;
    }
};