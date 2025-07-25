
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g =  nums[0] ;
        for(int& n : nums) {
            g = __gcd(g , n);
            if(g == 1) return true;    
        }
        return g == 1 ;
    }
};