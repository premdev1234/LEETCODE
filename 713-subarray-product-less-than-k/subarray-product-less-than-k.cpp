
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int left = 0;
        int count = 0;
        long long product = 1;

        for (int right = 0; right < n; ++right) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left++];
            }
            // All subarrays ending at right with start from left to right are valid
            count += right - left + 1;
        }
        return count;
    }
};









