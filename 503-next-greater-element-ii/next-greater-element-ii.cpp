class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n  = nums.size();
        vector<int> result(n,-1);
        stack<int> s ;
        for(int i =  2*n - 1 ; ~i ; --i){
            while(!s.empty() and nums[s.top()] <= nums[i%n])s.pop();
            if(!s.empty()) result[i%n] = nums[s.top()];
            s.push(i%n);
        }
        return move(result);
    }
};