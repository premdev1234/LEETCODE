class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int cnt=0;
        int len=0;
        if(i==-1) return n;
        while(j<n && i<n){
          if(nums[j]==0){
            cnt++;
            if(k<cnt) {
               while(nums[i]!=0) i++;
               i++;
                cnt--;
            }
          }
          len=max(len,j-i+1);
          j++;
        }
        return len;
    }
};