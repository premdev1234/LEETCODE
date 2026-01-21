class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // set<int> n ;
        // for(int x : nums){
        //     if(n.find(x) != n.end())return true ;
        //     n.insert(x);
        // }
        // return false;
        int n = (int)nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n-1 ; ++i)if(nums[i]==nums[i+1])return true;
        return false;
    }
};