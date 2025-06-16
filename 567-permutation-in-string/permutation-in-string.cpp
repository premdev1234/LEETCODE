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
void operator delete[](void* ptr){}
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        // if(s1.length() == s2.length()) return s1==s2 ;
        int m =  s1.length() , n = s2.length();
        array<int,26> a = {} , b = {};
        for(int i = 0 ; i< m ;++i){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        if(a == b) return true;
        for(int i = m ;  i< n ; ++i){
            b[s2[i]-'a']++;
            b[s2[i-m]-'a']--;
            if(a == b) return true;
        }
        return false;
    }
};