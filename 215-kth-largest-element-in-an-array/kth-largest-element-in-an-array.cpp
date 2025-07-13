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
    // int partition(vector<int>&nums , int l , int r){
    //     int p =  nums[r];
    //     int i = l ;
    //     for(int j = l ; j < r ; ++j) if(nums[j] <= p) swap(nums[i++],nums[j]);
    //     swap(nums[i],nums[r]);
    //     return i;
    // }
    // int qs(vector<int>&nums , int l ,int r , int k){
    //     if(l == r) return nums[l];
    //     int p = partition(nums,l,r);
    //     if(p == k) return nums[k];
    //     else if(p < k ) return qs(nums,p+1,r,k);
    //     else return qs(nums,l,p-1,k);
    // }
    int findKthLargest(vector<int>& nums, int k) {
        int n  =  nums.size();
        // method 1 : quick select tle :
        // return qs(nums,0,n-1,n-k); // kth largest is n-k th smallest 

        //  method 2 simplest fast enough to be top 90percent and even space
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];
        
        // method 3
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        
        for (int num: nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }
        
        vector<int> count(maxValue - minValue + 1);
        for (int num: nums) {
            count[num - minValue]++;
        }
        
        int remain = k;
        for (int num = count.size() - 1; num >= 0; num--) {
            remain -= count[num];
            if (remain <= 0) {
                return num + minValue;
            }
        }
        
        return -1;
    }
};