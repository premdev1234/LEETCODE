class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n  = (int)nums.size();
        long long score = 0 ;
        vector<bool> marked(n,false);
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](int i , int j){
            if(nums[i] != nums[j]) return nums[i] < nums[j];
            return i < j ;
        });
        for(int i = 0 ; i < n ; ++i){
            int idx = indices[i];
            if(marked[idx])continue;
            score += nums[idx];
            if(idx-1 >= 0)marked[idx-1] = true ;
            if(idx+1 < n)marked[idx+1] = true ;
            marked[idx] = true;
        }
        return score;
    }
};