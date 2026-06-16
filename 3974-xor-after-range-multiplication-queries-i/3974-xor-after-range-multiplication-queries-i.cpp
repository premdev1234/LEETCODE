class Solution {
public:
    const int mod = 1e9+7 ;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q : queries){
            int l =q[0] , r = q[1] , k = q[2] , v = q[3] ;
            while(l <= r){
                nums[l] = (1LL * nums[l] * v)%mod ;
                l += k ;
            }
        }
        int ans = 0 ;
        for(int num : nums) ans ^= num ;
        return ans ;
    }
};