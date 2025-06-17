// class Solution {
// public:
//     pair<bool, int> binary_search(int left, int right, vector<int>& nums) {
//         if (left > right || left < 0 || right >= nums.size()) return {false, -1};
//         int mid = left + (right - left) / 2;

//         // Check if this is the unique element
//         if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
//             (mid == nums.size() - 1 || nums[mid] != nums[mid + 1])) {
//             return {true, nums[mid]};
//         }

//         // Check how to recurse based on pairing pattern
//         bool leftIsEven = (mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
//                           (mid % 2 == 1 && nums[mid] == nums[mid - 1]);

//         if (leftIsEven)
//             return binary_search(mid + 1, right, nums);
//         else
//             return binary_search(left, mid - 1, nums);
//     }

//     int singleNonDuplicate(vector<int>& nums) {
//         return binary_search(0, nums.size() - 1, nums).second;
//     }
// };
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1) --mid; // ensure mid is even
            if (nums[mid] == nums[mid + 1])
                left = mid + 2;
            else
                right = mid;
        }
        return nums[left];
    }
};
