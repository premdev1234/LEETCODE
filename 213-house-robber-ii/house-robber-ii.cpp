class Solution {
public:
    int HouseRobberI(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; ++i) {
            int curr = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(HouseRobberI(nums, 0, n - 2), HouseRobberI(nums, 1, n - 1));
    }
};
