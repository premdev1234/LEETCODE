class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n =  nums.size();
        // vector<int> prefix(n) , suffix(n);
        // prefix[0] = suffix[n-1] = 0 ;
        // for(int i = 1 ; i < n ; i++) prefix[i] = prefix[i-1]+nums[i-1];
        // for(int i = n-2 ; i >= 0 ; --i) suffix[i] = suffix[i+1]+nums[i+1];
        // for(int i = 0 ; i < n ; ++i){
        //     if(prefix[i] == suffix[i]) return i ;
        // }
        // return -1 ;
        int total =  accumulate(nums.begin(),nums.end(),0);
        int left =0 , right;
        for(int i = 0 ; i < n ; i++){
            right = total - left -nums[i];
            if(left ==  right) return i ;
            left += nums[i];
        }
        return -1;
    }
};