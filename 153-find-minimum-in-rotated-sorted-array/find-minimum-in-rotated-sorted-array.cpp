class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            // Minimum must be in the unsorted half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid; // mid could be the min
            }
        }
        return nums[low];
    }
};
