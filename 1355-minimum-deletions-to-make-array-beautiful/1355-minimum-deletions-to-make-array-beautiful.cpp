class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int del = 0;
        int n = (int)nums.size();
        for(int i = 0 ; i < n-1 ; ++i){
            int idx = i - del ;
            if(idx&1) continue;
            if(nums[i] == nums[i+1])del++;
        }
        return ((n-del)&1 ? del+1 : del);
    }
};