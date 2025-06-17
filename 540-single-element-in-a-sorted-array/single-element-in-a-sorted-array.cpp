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

// Custom memory pool for dynamic allocation using a pre-allocated buffer
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1) --mid; // ensure mid is even
            if (nums[mid] == nums[mid + 1]) left = mid + 2;
            else right = mid;
        }
        return nums[left];
    }
};
