class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 =  nums[0];
        int prev2 = 0;
        for(int i  = 1 ;  i < nums.size()-1; i++){
            int curr = max( prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        int ans = prev1;
        if( nums.size() > 1){
        prev1 = nums[1];
        prev2 = 0;
        for(int i  = 2 ;  i < nums.size(); i++){
            int curr = max( prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        }
        ans = max(ans,prev1);
        return ans;
        
    }
};