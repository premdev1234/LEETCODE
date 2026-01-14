class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int r = 0 ;
        for(int&x:nums)r ^= x ;
        if(r == 0)return true;
        int n = (int)nums.size();
        return !(n&1);
    }
};