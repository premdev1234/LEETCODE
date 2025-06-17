
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
    string longestPalindrome(string s) {
        string t = "@";
        for (char c : s)
            t += "#" + string(1, c);
        t += "#$";

        int center = 0, right = 0;
        int bestLen = 0, bestCenter = 0;
        
        for (int i = 1; i < t.size() - 1; ++i) {
            int mirror = 2 * center - i;
            int radius = 0;

            if (i < right)
                radius = min(right - i, 0); // if we had p[], this would be p[mirror]

            while (t[i + 1 + radius] == t[i - 1 - radius])
                ++radius;

            if (i + radius > right) {
                center = i;
                right = i + radius;
            }

            if (radius > bestLen) {
                bestLen = radius;
                bestCenter = i;
            }
        }

        int start = (bestCenter - bestLen) / 2;
        return s.substr(start, bestLen);
    }
};
