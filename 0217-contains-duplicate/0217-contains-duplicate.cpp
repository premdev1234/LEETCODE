class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> n ;
        for(int x : nums){
            if(n.find(x) != n.end())return true ;
            n.insert(x);
        }
        return false;
    }
};