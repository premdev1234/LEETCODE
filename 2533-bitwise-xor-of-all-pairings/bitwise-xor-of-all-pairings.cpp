class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n =  nums1.size() , m = nums2.size();
        int a = 0 , b = 0 ;
        if(m%2 != 0){
            for(int num : nums1) a ^=num ;
        }
        if(n%2 != 0){
            for(int num : nums2) b ^= num ;
        }
        return a^b ;
    }
};