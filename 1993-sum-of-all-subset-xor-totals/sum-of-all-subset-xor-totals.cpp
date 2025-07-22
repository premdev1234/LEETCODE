class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orall = 0 ;
        for(int num : nums)orall |=  num;
        return orall*(1 << (nums.size()-1));
    }
};