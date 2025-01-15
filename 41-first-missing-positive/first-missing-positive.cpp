class Solution {
public:
    void swap(vector<int>& nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Place each number in its correct position if possible
        for (int i = 0; i < n; i++) {
            // Ensure nums[i] is within bounds and not already in the correct position
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int targetIdx = nums[i] - 1;
                std::swap(nums[i], nums[targetIdx]);
            }
        }

        // Identify the first missing positive
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers are in the correct position, return n + 1
        return n + 1;
    }
};