class Solution {
public:
    unsigned long long dp[1001]{};
    int combinationSum4(vector<int>& coins, int target) {
        const int n = coins.size();
        dp[0] = 1;
        sort(begin(coins),end(coins)); // helpful if pruning
        for(int i = 1 ; i <= target ; ++i){
            for(int coin : coins){
                if(coin <= i and i-coin >= 0) dp[i] += dp[i-coin];
            }
        }
        return dp[target] >INT_MAX ? -1 : static_cast<int>(dp[target]);}
};
