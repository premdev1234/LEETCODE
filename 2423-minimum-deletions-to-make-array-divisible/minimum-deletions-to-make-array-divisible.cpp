class Solution {
    public:
        int minOperations(vector<int>& nums, vector<int>& numsDivide) {
            function<int(int, int)> gcd = [&](int a, int b) {
                return b == 0 ? a : gcd(b, a % b);
            };
    
            int GCD = numsDivide[0];
            for (int i = 1; i < numsDivide.size(); i++) {
                GCD = gcd(GCD, numsDivide[i]);
            }
    
            sort(nums.begin(), nums.end());
    
            for (int i = 0; i < nums.size(); i++) {
                if (GCD % nums[i] == 0) {
                    return i;
                }
            }
            return -1; 
        }
    };