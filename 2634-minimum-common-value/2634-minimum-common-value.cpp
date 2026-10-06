class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 , j = 0 , n = (int)nums1.size() , m = (int)nums2.size();
        while(i <  n and j < m ){
            if(nums1[i] == nums2[j])return nums1[i];
            if(nums1[i] < nums2[j])++i;
            else ++j ;
        }
        while(i < n){
            if(nums1[i] == nums2[m-1])return nums2[m-1];
            ++i;
        }
        while(j < m){
            if(nums2[j] == nums1[n-1]) return nums1[n-1];
            ++j;
        }
        return -1;
    }
};