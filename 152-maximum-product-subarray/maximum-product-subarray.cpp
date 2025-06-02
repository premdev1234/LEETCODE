class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =  nums.size();
        int dp[n+1][2];
        // dp[i][0] = min product ending at i
        // dp[i][1] = max product ending at i
        dp[0][0] = dp[0][1] = nums[0];
        int res = nums[0];
        for(int i = 1 ; i < n ; i++){
            int val =  nums[i];
            if(val  < 0 ){
                dp[i][1] =  max(val , val*dp[i-1][0]);
                dp[i][0] =  min(val,  val*dp[i-1][1]);
            }else{
                dp[i][1] =  max(val,val*dp[i-1][1]);
                dp[i][0] =  min(val,val*dp[i-1][0]);
            }
            res =  max(res,dp[i][1]);
        }
        return res ;
    }
};