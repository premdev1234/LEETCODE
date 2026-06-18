class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0;

        for(int x : nums){
            if(x & 1) odd++;
            else even++;
        }

        int ans = max(odd, even);

        for(int start = 0; start < 2; start++){
            int need = start;
            int len = 0;
            for(int x : nums){
                if((x & 1) == need){
                    len++;
                    need ^= 1;
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }
};