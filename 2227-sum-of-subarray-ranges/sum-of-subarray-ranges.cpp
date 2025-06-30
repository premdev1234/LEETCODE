class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0 ;
        int n =  nums.size();
        for(int i = 0 ; i< n-1 ; i++){
            int mx = nums[i] , mn = nums[i];
            for(int j = i+1 ; j < n ; j++){
                mx = max(nums[j],mx) , mn =  min(nums[j],mn);
                sum += (mx-mn) ;
            }
        }
        return sum ;
    }
};