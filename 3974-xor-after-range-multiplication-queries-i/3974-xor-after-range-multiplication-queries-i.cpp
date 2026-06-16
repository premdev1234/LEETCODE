class Solution {
public:
    const int mod = 1e9+7 ;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> res(nums.begin(),nums.end());
        for(auto q : queries){
            int l =q[0] , r = q[1] , k = q[2] , v = q[3] ;
            while(l <= r){
                res[l] = (res[l] * v)%mod ;
                l += k ;
            }
        }
        int ans = 0 ;
        for(int num : res) ans ^= num ;
        return ans ;
    }
};