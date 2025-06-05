class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;

        // Step 1: Find min and max values
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        int range = maxVal - minVal + 1;

        // Step 2: Initialize count array
        vector<int> count(range, 0);

        // Step 3: Count frequencies
        for (int num : nums) {
            count[num - minVal]++;
        }

        // Step 4: Compute prefix sums
        for (int i = 1; i < range; ++i) {
            count[i] += count[i - 1];
        }

        // Step 5: Stable placement using reverse traversal
        vector<int> sorted(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int idx = nums[i] - minVal;
            sorted[--count[idx]] = nums[i];
        }

        return sorted;
    }
};
