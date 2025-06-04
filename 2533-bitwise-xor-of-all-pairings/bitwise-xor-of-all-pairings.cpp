class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a = 0 , b = 0 ;
        if(nums2.size()%2 != 0){
            for(int num : nums1) a ^=num ;
        }
        if(nums1.size() % 2 != 0){
            for(int num : nums2) b ^= num ;
        }
        return a^b ;
    }
};