class Solution {
public:
    int combinationSum4(vector<int>& coins, int target) {
        int n =  coins.size() ; sort(coins.begin(),coins.end());
        vector<__int128_t> dp(target+1,0);
        dp[0] = 1 ;
        for(int i = 1 ; i <= target ; i++){
            for(int coin  : coins){
                if(i-coin >= 0 ) dp[i] += dp[i-coin] ;
            }
        }
        return dp[target];
    }
};