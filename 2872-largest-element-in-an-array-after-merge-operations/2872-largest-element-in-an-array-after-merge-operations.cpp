class Solution {
public:
    long long maxArrayValue(vector<int>& nu) {
        int n = (int)nu.size();
        vector<long long> nums(nu.begin(),nu.end());
        long long ans = nums[n-1];
        for(int i = n-2 ; i >= 0 ; --i){
            if(nums[i] <= nums[i+1])nums[i] += nums[i+1];
            ans = max(ans,1LL*nums[i]);
        }
        return ans;
    }
};