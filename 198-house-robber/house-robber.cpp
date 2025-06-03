class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0, curr;

        for(int i: nums){
            curr = max(prev1+i, prev2);
            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }
};