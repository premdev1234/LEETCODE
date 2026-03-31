class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> ans = {{}};
        int n = 1 ;
        for(int num:nums){
            for(int i = 0 ; i < n  ;  ++i){
                ans.push_back(ans[i]);
                ans.back().push_back(num);
            }
            n += n ;
        }
        return ans ;
    }
};