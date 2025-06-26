class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // naive bruteforce
        // int n  = nums.size();
        // unordered_map<int,vector<int>> indexes ;
        // for(int i = 0 ; i < n ; ++i){
        //     if(indexes.find(nums[i]) != indexes.end()){
        //         for(int& idx : indexes[nums[i]]){
        //             if(abs(i-idx) <= k) return true;
        //         }
        //     }
        //     indexes[nums[i]].push_back(i);
        // }
        // return false;

        // optimized
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i]))
                return true;
            window.insert(nums[i]);
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};
